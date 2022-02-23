#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <nvboard.h>

int main(int argc, char** argv, char** env){
	VerilatedContext* contextp =  new VerilatedContext;
	contextp->commandArgs(argc, argv);
	Vtop* top = new Vtop(contextp);
	
	Verilated::traceEverOn(true);

	VerilatedVcdC* tfp = new VerilatedVcdC;
	top->trace(tfp, 99);
	tfp->open("obj_dir/simx.vcd");

    nvboard_bind_all_pins(&dut);
    nvboard_init();

	int sim_time = 10;
	while(!contextp->gotFinish() || contextp->time() < sim_time){
		contextp->timeInc(1);
		int a = rand() & 1;
		int b = rand() & 1;

		top->a = a;
		top->b = b;
		top->eval();
		tfp->dump(contextp->time());

		printf("a = %d, b = %d, f = %d\n", a, b, top->f);
        nvboard_update();
		assert(top->f == a ^ b);
	}
	tfp->close();
    nvboard_quit();
}
