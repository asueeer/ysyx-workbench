build:
	verilator -Wall --trace --cc --exe --build main.cpp mux41v2.v

sim:
	rm -rf obj_dir
	make build && obj_dir/Vmux41v2

wave:
	gtkwave obj_dir/dump.vcd

clean:
	rm -rf obj_dir