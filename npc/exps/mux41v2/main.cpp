#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/Vmux41v2.h"

VerilatedContext *contextp = NULL;
VerilatedVcdC *tfp = NULL;

static Vmux41v2 *top;

void step_and_dump_wave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void sim_init() {
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new Vmux41v2;
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

    top->x0 = 0b0;
    top->x1 = 0b0;
    top->x2 = 0b0;
    top->x3 = 0b0;
    top->y = 0b0;
    step_and_dump_wave();   // 将x0~x3和y均初始化为“0”

    top->x0 = 0b11;
    top->y = 0b00;
    step_and_dump_wave();

    top->x1 = 0b01;
    top->y = 0b01;
    step_and_dump_wave();

    top->x2 = 0b10;
    top->y = 0b10;
    step_and_dump_wave();

    top->x3 = 0b11;
    top->y = 0b11;
    step_and_dump_wave();

    sim_exit();
}
