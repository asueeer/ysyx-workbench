typedef struct watchpoint {
    int NO;
    struct watchpoint *next;

    /* TODO: Add more members if necessary */
    char expr[128];
    word_t new_val;
    word_t old_val;
} WP;

WP *check_and_update_wps();

WP *new_wp();

void info_wp_pool();

void info_watchpoints();

int delete_wp(int n);