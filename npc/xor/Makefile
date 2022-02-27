build:
	verilator -Wall --trace --cc --exe --build csrc/sim_main.cpp vsrc/top.v

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	rm -rf obj_dir
	make build && obj_dir/Vtop

include ../../Makefile
