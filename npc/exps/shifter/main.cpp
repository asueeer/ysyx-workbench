#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/Vshifter.h"
#include <stdio.h>

VerilatedContext *contextp = NULL;
VerilatedVcdC *tfp = NULL;

static Vshifter *top;

void step_and_dump_wave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void sim_init() {
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new Vshifter;
    contextp->traceEverOn(true);
    top->trace(tfp, 0);
    tfp->open("obj_dir/dump.vcd");
}

void sim_exit() {
    step_and_dump_wave();
    tfp->close();
}

int main() {
    sim_init();

    top->sel = 0b000;
    top->A = 0b0001;
    top->B = 0b0001;
    step_and_dump_wave();
    // todo


    sim_exit();
}
