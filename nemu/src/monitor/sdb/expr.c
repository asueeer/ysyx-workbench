#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <string.h>
#include <stdlib.h>

enum {
    TK_NOTYPE = 256, TK_EQ, TK_INT,

    /* TODO: Add more token types */

};

void token_info();

static struct rule {
    const char *regex;
    int token_type;
} rules[] = {

        /* TODO: Add more rules.
         * Pay attention to the precedence level of different rules.
         */

        {" +",      TK_NOTYPE},   // spaces
        {"\\+",     '+'},         // plus
        {"-[0-9]+", TK_INT},
        {"\\-",     '-'},         // minus
        {"\\*",     '*'},         // multiply
        {"\\/",     '/'},         // divide
        {"\\(",     '('},
        {"\\)",     ')'},
        {"[0-9]+",  TK_INT},      // Integer
        {"==",      TK_EQ},       // equal
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
    int i;
    char error_msg[128];
    int ret;

    for (i = 0; i < NR_REGEX; i++) {
        ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
        if (ret != 0) {
            regerror(ret, &re[i], error_msg, 128);
            panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
        }
    }
}

typedef struct token {
    int type;
    char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

static bool make_token(char *e) {
    int position = 0;
    int i;
    regmatch_t pmatch;

    nr_token = 0;

    while (e[position] != '\0') {
        /* Try all rules one by one. */
        for (i = 0; i < NR_REGEX; i++) {
            if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
                if (nr_token >= 32) {
                    panic("too much tokens\n");
                }
                char *substr_start = e + position;
                int substr_len = pmatch.rm_eo;

                Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
                    i, rules[i].regex, position, substr_len, substr_len, substr_start);

                position += substr_len;

                /* TODO: Now a new token is recognized with rules[i]. Add codes
                 * to record the token in the array `tokens'. For certain types
                 * of tokens, some extra actions should be performed.
                 */
                if (substr_len > 30) {
                    panic("make_token: substr_len > 30\n");
                }
                switch (rules[i].token_type) {
                    case TK_INT:
                        strncpy(tokens[nr_token].str, substr_start, substr_len);
                        tokens[nr_token].str[substr_len] = '\0';
                        tokens[nr_token].type = rules[i].token_type;
                        nr_token++;
                        break;
                    case TK_NOTYPE:
                        break;
                    default:
                        tokens[nr_token].type = rules[i].token_type;
                        nr_token++;
                }
                break;
            }
        }

        if (i == NR_REGEX) {
            printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
            return false;
        }
    }

    return true;
}

bool check_parentheses(int p, int q) {
    return tokens[p].type == '(' && tokens[q].type == ')';
}


/**
 * the operation op1 is less than op2 or equal it
 * */
bool leq(int op1, int op2) {
    int type1 = tokens[op1].type;
    int type2 = tokens[op2].type;
    bool flag1 = type1 == '*' || type2 == '/';
    bool flag2 = type2 == '+' || type2 == '-';
    return !(flag1 && flag2);
}

bool is_cacl_op(int op) {
    int type = tokens[op].type;
    bool flag1 = type == '*' || type == '/';
    bool flag2 = type == '-' || type == '+';
    return flag1 || flag2;
}

/*
 * the position of main op in the expr(p,q)
*/
int op_main(int p, int q) {
    /**
     * the parentheses counter
     * if meet '(': cnt++;
     * if meet ')': cnt--;
     * */
    int cnt = 0;
    int ret = -1;
    for (int i = p; i <= q; ++i) {
        if (cnt < 0) {
            return -1;
        }
        if (tokens[i].type == '(') {
            cnt++;
            continue;
        }
        if (tokens[i].type == ')') {
            cnt--;
            continue;
        }
        if (is_cacl_op(i) && (ret < 0 || leq(i, ret))) {
            ret = i;
        }
    }
    return ret;
}

word_t eval(int p, int q, bool *success) {
    if (!success) {
        return 0;
    }
    if (p > q) {
        return 0;
    }
    printf("hi\n");
    if (p == q) {
        printf("TK_INT is %d\n", TK_INT);
        // token should be a number, or it is a bad expression
        if (tokens[p].type == TK_INT) {
            printf("hi there\n");
            return atoi(tokens[p].str);
        } else {
            *success = false;
            return 0;
        }
    }
    if (check_parentheses(p, q) == true) {
        return eval(p + 1, q - 1, success);
    }
    int op = op_main(p, q);
    if (op < 0) {
        success = false;
        return 0;
    }
    word_t val1 = eval(p, op - 1, success);
    word_t val2 = eval(op + 1, q, success);

    switch (tokens[op].type) {
        case '+':
            return val1 + val2;
        case '-':
            return val1 - val2;
        case '*':
            return val1 * val2;
        case '/':
            return val1 / val2;
        default:
            *success = false;
            return 0;
    }
}

void token_info() {
    for (int i = 0; i < nr_token; ++i) {
        Log("tokens[%d]: str is %s, type is %d\n", i, tokens[i].str, tokens[i].type);
    }
}

word_t expr(char *e, bool *success) {
    if (!make_token(e)) {
        *success = false;
        return 0;
    }
    token_info();

    *success = true; // suppose it is true
    return eval(0, nr_token, success);
}
