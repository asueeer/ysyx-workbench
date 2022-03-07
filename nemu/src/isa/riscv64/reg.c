#include <isa.h>
#include <stdio.h>
#include <string.h>
#include "local-include/reg.h"

const char *regs[] = {
        "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
        "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
        "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
        "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

word_t isa_reg_str2val(const char *s, bool *success);
void display_all_regs();
void display_reg_val(const char *reg_name, word_t reg_val);

void isa_reg_display(char *s) {
    if (s == NULL) {
        display_all_regs();
        return;
    }
    bool success;
    word_t reg_val = isa_reg_str2val(s, &success);
    if(success == 0){
        display_reg_val(s, reg_val);
    }else{
        printf("no register named \"%s\"\n", s);
    }
}

void display_all_regs() {
    for (int i = 0; i < 32; ++i) {
         display_reg_val(regs[i], gpr(i));
    }
    display_reg_val("pc", cpu.pc);
}

void display_reg_val(const char *reg_name, word_t reg_val){
    // %-12s 表示字符串输出, 至少占12个字符宽度, -负号表示强制左对齐
    printf("%-12s 0x%-12lx %-12ld\n", reg_name, reg_val, reg_val);
}

word_t isa_reg_str2val(const char *s, bool *success) {
    *success = 1;
    if(strcmp(s, "pc")==0){
        return cpu.pc;
    }
    for (int i = 0; i < 32; ++i) {
        if (strcmp(s, regs[i]) == 0) {
            return gpr(i);
        }
    }
    *success = 0;
    return 0;
}
