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
        return NULL;
    }
    WP *ret = free_;
    free_ = free_->next;
    ret->next = NULL;
    if (head == NULL) {
        head = ret;
        return ret;
    }
    WP *cur = head; // find list tail
    while (cur->next != NULL) {
        cur = cur->next;
    }
    // now cur is tail
    cur->next = ret;
    return ret;
}

WP *check_and_update_wps() {
    WP *cur = head;
    bool success;
    while (cur != NULL) {
        cur->old_val = cur->new_val;
        cur->new_val = expr(cur->expr, &success);
        if (cur->old_val != cur->new_val) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void free_wp(WP *wp) {
    wp->next = free_;
    free_ = wp;
}

int delete_wp(int n) {
    WP *cur = head;
    while (cur != NULL) {
        cur = cur->next;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (cur == NULL) {
            return -1;
        }
        cur = cur->next;
    }
    free_wp(cur);
    return 0;
}