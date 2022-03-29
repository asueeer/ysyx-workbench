#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

static void gen_rand_expr();

static void gen_num();

static void gen(char c);

static int choose(int a);

static void gen_rand_op();


// this should be enough
static char buf[65536] = {};
int buf_used = 0;
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
        "#include <stdio.h>\n"
        "int main() { "
        "  unsigned result = %s; "
        "  printf(\"%%u\", result); "
        "  return 0; "
        "}";

static void gen_num() {
    int a = rand();
    int mod = 100;
    if (a % mod < 10) {
        return gen_num();
    }
    sprintf(&buf[buf_used], "%d", a % mod);
    buf_used += 2;
    buf[buf_used] = '\0';
}

static void gen(char c) {
    buf[buf_used] = c;
    buf_used++;
    buf[buf_used] = '\0';
}

static int choose(int a) {
    return rand() % a;
}

static void gen_rand_op() {
    char ops[4] = {'+', '-', '*', '/'};
    buf[buf_used] = ops[choose(4)];
    buf_used++;
    buf[buf_used] = '\0';
}

int cnt = 0;

static void gen_rand_expr() {
    cnt++;
    if (cnt > 500) {
        return;
    }
    int rand = choose(3);
    if (rand == 0) {
        gen_num();
        return;
    }
    if (rand == 1) {
        gen('(');
        gen_rand_expr();
        gen(')');
        return;
    }
    if (rand == 2) {
        gen_rand_expr();
        gen_rand_op();
        gen_rand_expr();
        return;
    }
}

void clear_buf() {
    for (int i = 0; i < 65535; ++i) {
        buf[i] = '\0';
    }
    buf_used = 0;
    cnt = 0;
    for (int i = 0; i < 65535; ++i) {
        code_buf[i] = '\0';
    }
}

int too_long() {
    return buf_used > 50;
}

int no_op() {
    for (int i = 0; i < buf_used; ++i) {
        if (buf[i] == '/' || buf[i] == '+' || buf[i] == '-' || buf[i] == '*') {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int seed = time(0);
    srand(seed);
    int loop = 1;
    if (argc > 1) {
        sscanf(argv[1], "%d", &loop);
    }
    int i;
    for (i = 0; i < loop; i++) {
        gen_rand_expr();
        if (too_long() || no_op()) {
            clear_buf();
            continue;
        }
        sprintf(code_buf, code_format, buf);

        FILE *fp = fopen("/tmp/.code.c", "w");
        assert(fp != NULL);
        fputs(code_buf, fp);
        fclose(fp);

        int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
        if (ret != 0) continue;

        fp = popen("/tmp/.expr", "r");
        assert(fp != NULL);

        int result;
        fscanf(fp, "%d", &result);
        pclose(fp);
        if (result <= 0) {
            clear_buf();
            continue;
        }
        // overflow
        if (result > 100000){
            clear_buf();
            continue;
        }
        printf("%u %s\n", result, buf);
        clear_buf();
    }
    return 0;
}
