build:
	verilator -Wall --trace --cc --exe build csrc/main.cpp vsrc/example.v

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	make build && obj_dir/Vtop

include ../Makefile
