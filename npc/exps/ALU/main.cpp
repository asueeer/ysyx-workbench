#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/VALU.h"

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

int main() {
    sim_init();

    top->sel = 0b000;
    top->A = 0b0001;
    top->B= 0b0001;
    step_and_dump_wave();

    for (int i = -8; i < 7; ++i) {
        for (int j =-8; j < 7; ++j) {

        }
    }

    sim_exit();
}
