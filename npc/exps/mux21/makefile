build:
	verilator -Wall --trace --cc --exe --build main.cpp mux21.v

sim:
	rm -rf obj_dir
	make build && obj_dir/Vmux21

wave:
	gtkwave obj_dir/dump.vcd