#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include "sdb.h"
#include "memory/paddr.h"

static int is_batch_mode = false;
static char *delim = " ";

void init_regex();

void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char *rl_gets() {
    static char *line_read = NULL;

    if (line_read) {
        free(line_read);
        line_read = NULL;
    }

    line_read = readline("(nemu) ");

    if (line_read && *line_read) {
        add_history(line_read);
    }

    return line_read;
}

static int cmd_c(char *args) {
    cpu_exec(-1);
    return 0;
}

static int cmd_q(char *args) {
    nemu_state.state = NEMU_END; // why?
    return -1;
}

static int cmd_si(char *args) {
    int n = 1;
    if (args != 0) {
        n = atoi(args);
        if (n == 0) {
            printf("args \"%s\" might not a valid number?\n", args);
            return 0;
        }
    }
    cpu_exec(n);
    return 0;
}

static int cmd_info(char *args) {
    char *ptr = strtok(args, delim);
    if (strcmp(ptr, "i")) {
        ptr = strtok(NULL, delim);
        isa_reg_display(ptr);
    }
    return 0;
}

static int cmd_x(char *args) {
    char *ptr = strtok(args, delim);
    int N = atoi(ptr);
    ptr = strtok(NULL, delim);
    if (!ptr) {
        printf("cmd_x: strtok fail.\n");
        return 0;
    }
    word_t addr = strtol(ptr, NULL, 16);
    for (int i = 0; i < N; ++i) {
        printf("\x1b[94m0x%lx\x1b[0m: 0x%lx \t%ld\n", addr, paddr_read(addr, 4), paddr_read(addr, 4));
        addr += 4;
    }
    return 0;
}

static int cmd_p(char *args) {
    bool success = true;
    word_t val = expr(args, &success);
    if (!success) {
        printf("cmp_p: parse expression failed\n");
        return 0;
    }
    printf("the val is 0x%lx \t %ld\n", val, val);
    return 0;
}


static int cmd_w(char *args) {
    WP *wp = new_wp();
    strcpy(wp->expr, args);
    return 0;
}


static int cmd_d(char *args) {
    int n = 1;
    if (args != 0) {
        n = atoi(args);
        if (n == 0) {
            printf("args \"%s\" might not a valid number?\n", args);
            return 0;
        }
    }
    if (delete_wp(n) < 0){
        printf("delete wp %s failed.\n", args);
        return 0;
    }
    return 0;
}

static int cmd_test_expr(char *args) {
    FILE *fp = fopen("/tmp/input", "r");
    int nbuf = 65536;
    char buf[nbuf];
    word_t res = 0;
    int cnt = 0;
    for (int i = 0; i < nbuf; ++i) {
        bool success = true;
        if (fscanf(fp, "%ld %s\n", &res, buf) < 0) {
            continue;
        }
        if (res != expr(buf, &success) || !success) {
            printf("expr %s, res should be %ld, you give %ld\n", buf, res, expr(buf, &success));
            if (!success) {
                continue;
            }
            printf("test fail\n");
            assert(0);
        }
        cnt++;
    }
    fclose(fp);
    printf("test %d times, expr test success.\n", cnt);
    return 0;
}

static int cmt_test_wp(char *args) {
    info_wp();
    return 0;
}


static int cmd_help(char *args);

static struct {
    const char *name;
    const char *description;

    int (*handler)(char *);
} cmd_table[] = {
        {"help",   "Display informations about all supported commands",  cmd_help},
        {"c",      "Continue the execution of the program",              cmd_c},
        {"q",      "Exit NEMU",                                          cmd_q},

        /* TODO: Add more commands */
        {"si",     "step by machine instructi rather than source lines", cmd_si},
        {"i",      "display info about regist ers, watch points, etc.",  cmd_info},
        {"x",      "examine memory at address expr",                     cmd_x},
        {"p",      "examine an expression's value",                      cmd_p},
        {"w",      "set a watchpoint for an expression",                 cmd_w},
        {"d",      "delete a watchpoint for n",                          cmd_d},
        {"t_expr", "test the expr func is right",                        cmd_test_expr},
        {"t_wp",   "test the watchpoint functions",                      cmt_test_wp},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
    /* extract the first argument */
    char *arg = strtok(NULL, " ");
    int i;

    if (arg == NULL) {
        /* no argument given */
        for (i = 0; i < NR_CMD; i++) {
            printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        }
    } else {
        for (i = 0; i < NR_CMD; i++) {
            if (strcmp(arg, cmd_table[i].name) == 0) {
                printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
                return 0;
            }
        }
        printf("Unknown command '%s'\n", arg);
    }
    return 0;
}

void sdb_set_batch_mode() {
    is_batch_mode = true;
}

void sdb_mainloop() {
    // printf("i am in main loop\n");
    if (is_batch_mode) {
        cmd_c(NULL);
        return;
    }

    for (char *str; (str = rl_gets()) != NULL;) {
        char *str_end = str + strlen(str);

        /* extract the first token as the command */
        char *cmd = strtok(str, " ");
        if (cmd == NULL) { continue; }

        /* treat the remaining string as the arguments,
         * which may need further parsing
         */
        char *args = cmd + strlen(cmd) + 1;
        if (args >= str_end) {
            args = NULL;
        }

#ifdef CONFIG_DEVICE
        extern void sdl_clear_event_queue();
        sdl_clear_event_queue();
#endif

        int i;
        for (i = 0; i < NR_CMD; i++) {
            if (strcmp(cmd, cmd_table[i].name) == 0) {
                if (cmd_table[i].handler(args) < 0) { return; }
                break;
            }
        }

        if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
    }
}

void init_sdb() {
    /* Compile the regular expressions. */
    init_regex();

    /* Initialize the watchpoint pool. */
    init_wp_pool();
}
