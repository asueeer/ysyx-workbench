build:
	verilator -Wall --trace --cc --exe --build main.cpp shifter.v

sim:
	rm -rf obj_dir
	make build && obj_dir/VALU

wave:
	gtkwave obj_dir/dump.vcd

clean:
	rm -rf obj_dir