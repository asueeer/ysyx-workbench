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
    for (int i = -8; i < 7; ++i) {
        for (int j = -8; j < 7; ++j) {
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

    // 测试有符号的减法, 有符号的减法只关心溢出, 不关心进位/借位
    top->sel = 0b001;
    for (int i = -8; i < 7; ++i) {
        for (int j = -8; j < 7; ++j) {
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

    sim_exit();
    printf("ok.\n");
}
