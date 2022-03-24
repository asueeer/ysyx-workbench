typedef struct watchpoint {
    int NO;
    struct watchpoint *next;

    /* TODO: Add more members if necessary */
    char *e;
    word_t old_val;
} WP;

WP *check_and_update_wps();

WP *new_wp();

void info_wp();