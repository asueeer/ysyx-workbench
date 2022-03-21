#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <string.h>

enum {
    TK_NOTYPE = 256, TK_EQ, TK_INT,

    /* TODO: Add more token types */

};

static struct rule {
    const char *regex;
    int token_type;
} rules[] = {

        /* TODO: Add more rules.
         * Pay attention to the precedence level of different rules.
         */

        {" +",   TK_NOTYPE},   // spaces
        {"\\+",  '+'},         // plus
        {"\\-",  '-'},         // minus
        {"\\*",  '*'},         // multiply
        {"\\/",  '/'},         // divide
        {"\\(",  '('},
        {"\\)",  ')'},
        {"[1-9]\\d", TK_INT},      // Integer
        {"==",   TK_EQ},       // equal
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
                        break;
                    default:
                        tokens[nr_token].type = rules[i].token_type;
                }
                nr_token++;
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


word_t expr(char *e, bool *success) {
    printf("nr_token: %d\n", nr_token);
    printf("e: %s\n",e);
    if (!make_token(e)) {
        *success = false;
        return 0;
    };
    /* TODO: Insert codes to evaluate the expression. */


    for (int i = 0; i < nr_token; ++i) {

        printf("tokens[%d]: str is %s, type is %d\n", i, tokens[i].str, tokens->type);
    }

    *success = true;
    return strtol(e, NULL, 16);
}
