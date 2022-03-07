build:
	verilator -Wall --trace --cc --exe --build main.cpp mux41.v

sim:
	rm -rf obj_dir
	make build && obj_dir/Vmux41

wave:
	gtkwave obj_dir/dump.vcd