#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>

typedef struct watchpoint {
    int NO;
    struct watchpoint *next;

    /* TODO: Add more members if necessary */
    char *e;
    word_t old_val;
} WP;

word_t expr(char *e, bool *success);

WP *new_wp();

void info_wp();

#endif
