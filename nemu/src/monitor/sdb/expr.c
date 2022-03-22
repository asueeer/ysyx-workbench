#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <string.h>
#include <stdlib.h>

#define NTOKENS 32


enum {
    TK_NOTYPE = 256,
    TK_EQ,
    TK_NEQ,
    TK_INT,
    TK_INT_HEX,
    TK_REG,
    TK_DEREF,
    TK_NEGATIVE,
    TK_AND,

    /* TODO: Add more token types */
};
#define N_OP 7
static int operator[] = {
        '+',
        '-',
        '*',
        '/',
        TK_AND,
        TK_EQ,
        TK_NEQ,
};
#define N_SINGLE_OP 2
static int single_op[] = {
        TK_DEREF,
        TK_NEGATIVE,
};


void token_info();

static struct rule {
    const char *regex;
    int token_type;
} rules[] = {

        /* TODO: Add more rules.
         * Pay attention to the precedence level of different rules.
         */
        {" +",                     TK_NOTYPE},   // spaces
        {"\\+",                    '+'},         // plus
        {"\\-",                    '-'},         // minus
        {"\\*",                    '*'},         // multiply
        {"\\/",                    '/'},         // divide
        {"\\(",                    '('},
        {"\\)",                    ')'},
        {"\\$[a-z0-9]+",           TK_REG},      // reg
        {"(0[xX]){1}[0-9a-fA-F]+", TK_INT_HEX},  // Hex Integer
        {"[0-9]+",                 TK_INT},      // Decimal Integer
        {"==",                     TK_EQ},      // equal
        {"&&",                     TK_AND},
        {"!=",                     TK_NEQ},
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

static Token tokens[NTOKENS] __attribute__((used)) = {};
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
                if (nr_token >= NTOKENS) {
                    panic("too much tokens\n");
                }
                char *substr_start = e + position;
                int substr_len = pmatch.rm_eo;

                Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
                    i, rules[i].regex, position, substr_len, substr_len, substr_start);

                position += substr_len;

                if (substr_len > 30) {
                    panic("make_token: substr_len > 30\n");
                }
                switch (rules[i].token_type) {
                    case TK_NOTYPE:
                        break;
                    case TK_REG:
                        strncpy(tokens[nr_token].str, substr_start + 1, substr_len);
                        tokens[nr_token].str[substr_len] = '\0';
                        tokens[nr_token].type = rules[i].token_type;
                        nr_token++;
                        break;
                    default:
                        strncpy(tokens[nr_token].str, substr_start, substr_len);
                        tokens[nr_token].str[substr_len] = '\0';
                        tokens[nr_token].type = rules[i].token_type;
                        nr_token++;
                        break;
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
    bool cond1 = tokens[p].type == '(' && tokens[q].type == ')';
    if (!cond1) {
        return false;
    }
    int cnt = 1;
    for (int i = p + 1; i < q; ++i) {
        if (tokens[i].type == '(') {
            cnt++;
        }
        if (tokens[i].type == ')') {
            cnt--;
        }
        if (cnt == 0) {
            return false;
        }
    }
    bool cond2 = cnt == 1;
    return cond1 && cond2;
}


/**
 * the operation op1 is less than op2 or equal it
 * */
bool leq(int op1, int op2) {
    int type1 = tokens[op1].type;
    int type2 = tokens[op2].type;
    bool flag1 = type1 == '*' || type1 == '/';
    bool flag2 = type2 == '+' || type2 == '-';
    return !(flag1 && flag2);
}

bool is_cacl_op(int op) {
    for (int i = 0; i < N_OP; i++) {
        if (tokens[op].type == operator[i]) {
            return true;
        }
    }
    return false;
}

bool is_single_op(int op) {
    for (int i = 0; i < N_SINGLE_OP; ++i) {
        if (tokens[op].type == single_op[i]) {
            return true;
        }
    }
    return false;
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
        if (cnt > 0) {
            continue;
        }
        if (is_cacl_op(i) && (ret < 0 || leq(i, ret))) {
            ret = i;
        }
    }
    return ret;
}

bool valid_parentheses(int p, int q) {
    int cnt = 0;
    for (int i = p; i <= q; ++i) {
        if (cnt < 0) {
            return false;
        }
        if (tokens[i].type == '(') {
            cnt++;
            continue;
        }
        if (tokens[i].type == ')') {
            cnt--;
            continue;
        }
    }
    return true;
}

word_t eval(int p, int q, bool *success) {
    printf("p is %d, q is %d, success:%d\n", p, q, *success);
    if (!*success) {
        return 0;
    }
    if (p > q) {
        return 0;
    }
    if (!valid_parentheses(p, q)) {
        *success = false;
        return 0;
    }
    if (p == q) {
        // token should be a number, or it is a bad expression
        if (tokens[p].type == TK_INT) {
            printf("success: %d\n", *success);
            return atoi(tokens[p].str);
        } else if (tokens[p].type == TK_INT_HEX) {
            return strtol(tokens[p].str, NULL, 16);
        } else if (tokens[p].type == TK_REG) {
            word_t reg_val = isa_reg_str2val(tokens[p].str, success);
            return reg_val;
        } else {
            *success = false;
            return 0;
        }
    }
    if (is_single_op(p)) {
        if (tokens[p].type == TK_NEGATIVE) {
            return -eval(p + 1, q, success);
        }
        // todo
    }
    if (check_parentheses(p, q) == true) {
        return eval(p + 1, q - 1, success);
    }
    int op = op_main(p, q);
    if (op < 0) {
        *success = false;
        return 0;
    }
    long val1 = eval(p, op - 1, success);
    long val2 = eval(op + 1, q, success);
    printf("op is %d, val1 is %ld, val2 is %ld\n", op, val1, val2);
    printf("success: %d\n", *success);
    switch (tokens[op].type) {
        case '+':
            return (word_t) val1 + val2;
        case '-':
            return (word_t) val1 - val2;
        case '*':
            return (word_t) val1 * val2;
        case '/':
            if (val2 == 0) {
                *success = false;
                return 0;
            }
            return (word_t) val1 / val2;
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
    for (int i = 0; i < nr_token; ++i) {
        if (tokens[i].type == '*' && (i == 0 || is_cacl_op(i - 1) || is_single_op(i - 1))) {
            tokens[i].type = TK_DEREF;
        }
        if (tokens[i].type == '-' && (i == 0 || is_cacl_op(i - 1) || is_single_op(i - 1))) {
            tokens[i].type = TK_NEGATIVE;
        }
    }
    token_info();

    *success = true; // suppose it is true
    return eval(0, nr_token - 1, success);
}
