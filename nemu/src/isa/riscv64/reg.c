#include <isa.h>
#include <stdio.h>
#include "local-include/reg.h"

const char *regs[] = {
        "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
        "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
        "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
        "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

word_t isa_reg_str2val(const char *s, bool *success);

void isa_reg_display() {
    for (int i = 0; i < 32; ++i) {
        bool success;
        word_t reg_val = isa_reg_str2val(regs[i], &success);
        // %-12s 表示字符串输出, 至少占12个字符宽度, -负号表示强制左对齐
        printf("%-12s 0x%-12lx %-12ld\n", regs[i], reg_val, reg_val);
    }
    printf("%-12s 0x%-12lx %-12ld\n", "pc", cpu.pc, cpu.pc);
}

word_t isa_reg_str2val(const char *s, bool *success) {
    for (int i = 0; i < 32; ++i) {
        if (strcmp(s, regs[i]) == 0) {
            return gpr(i);
        }
    }
    *success = 0;
    return 0;
}
