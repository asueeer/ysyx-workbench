build:
	verilator -Wall --trace --cc --exe --build csrc/main.cpp vsrc/example.v

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	rm -rf obj_dir
	make build && obj_dir/Vexample

include ../Makefile
