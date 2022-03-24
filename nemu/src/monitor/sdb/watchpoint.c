#include <stdio.h>
#include "sdb.h"
#include <stdlib.h>
#define NR_WP 32


static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {

    int i;
    for (i = 0; i < NR_WP; i++) {
        wp_pool[i].NO = i;
        wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    }

    head = NULL;
    free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

void info_wp() {
    for (int i = 0; i < NR_WP; ++i) {
        printf("wp[%d]: no is %d, next wp no is %d\n", i, wp_pool[i].NO, wp_pool[i].next ? wp_pool[i].next->NO : -1);
    }
}

WP *new_wp() {
    if (free_ == NULL) {
        printf("no free watch point\n");
        assert(0);
    }
    WP *ret = free_;
    free_ = free_->next;
    return ret;
}

void free_wp(WP *wp) {
    wp->next = free_;
    free_ = wp;
}