#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/VALU.h"
#include <stdio.h>

VerilatedContext *contextp = NULL;
VerilatedVcdC *tfp = NULL;

static VALU *top;

void step_and_dump_wave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void sim_init() {
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new VALU;
    contextp->traceEverOn(true);
    top->trace(tfp, 0);
    tfp->open("obj_dir/dump.vcd");
}

void sim_exit() {
    step_and_dump_wave();
    tfp->close();
}

int over_flow(int i) {
    if (i > 7 || i < -8) {
        return 1;
    }
    return 0;
}

int carry_(int i) {
    return i > 15;
}

int borrow_(int i) {
    return i < 0;
}


int main() {
    sim_init();

    top->sel = 0b000;
    top->A = 0b0001;
    top->B = 0b0001;
    step_and_dump_wave();

    // 测试有符号的加法, 有符号加法只关心溢出 不关心进位/借位
    top->sel = 0b000;
    for (int i = -8; i <= 7; ++i) {
        for (int j = -8; j <= 7; ++j) {
            int sum = i + j;
            int of = over_flow(sum);
            sum &=0b1111;
            top->A = i;
            top->B = j;
            step_and_dump_wave();
            if (top->result != sum || top->overflow != of) {
                printf("i: %d, j: %d, your_sum: %d, your_of: %d\n", i, j, top->result, top->overflow);
                printf("sum should be: %d, of should be %d\n", sum, of);
                sim_exit();
                exit(0);
            }
        }
    }
    printf("test signed add ok.\n");

    // 测试无符号的加法, 无符号的加法只关心进位, 不关心溢出
    top->sel = 0b000;
    for (unsigned int i = 0; i <= 15; ++i) {
        for (unsigned int j = 0; j <= 15; ++j) {
            int sum = i + j;
            int carry = carry_(sum);
            sum &=0b1111;
            top->A = i;
            top->B = j;
            step_and_dump_wave();
            if (top->result != sum || top->carry != carry) {
                printf("i: %d, j: %d, your_sum: %d, your_carry: %d\n", i, j, top->result, top->carry);
                printf("sum should be: %d, carry should be %d\n", sum, carry);
                sim_exit();
                exit(0);
            }
        }
    }
    printf("test unsigned add ok.\n");

    // 测试有符号的减法, 有符号的减法只关心溢出, 不关心进位/借位
    top->sel = 0b001;
    for (int i = -8; i <= 7; ++i) {
        for (int j = -8; j <= 7; ++j) {
            int sum = i - j;
            int of = over_flow(sum);
            sum &=0b1111;
            top->A = i;
            top->B = j;
            step_and_dump_wave();
            if (top->result != sum || top->overflow != of) {
                printf("i: %d, j: %d, your_sum: %d, your_of: %d\n", i, j, top->result, top->overflow);
                printf("sum should be: %d, of should be %d\n", sum, of);
                sim_exit();
                exit(0);
            }
        }
    }
    printf("test signed sub ok.\n");

    // 测试无符号的减法, 无符号的减法只关心借位, 不关心溢出
    top->sel = 0b001;
    for (unsigned int i = 0; i <= 15; ++i) {
        for (unsigned int j = 0; j <= 15; ++j) {
            int sum = i - j;
            int borrow = borrow_(sum);
            sum &=0b1111;
            top->A = i;
            top->B = j;
            step_and_dump_wave();
            if (top->result != sum || top->carry != !borrow) {
                printf("i: %d, j: %d, your_sum: %d, your_carry: %d\n", i, j, top->result, top->carry);
                printf("sum should be: %d, carry should be %d\n", sum, !borrow);
                sim_exit();
                exit(0);
            }
        }
    }
    printf("test unsigned sub ok.\n");

    sim_exit();
    printf("ok.\n");
}
