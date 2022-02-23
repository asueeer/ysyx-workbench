NVBOARD = /home/asueeer/Desktop/nvboard

clean:
	rm -rf build

generate:
	make clean
	mkdir build 
	python $(NVBOARD)/scripts/auto_pin_bind.py constr/top.nxdc build/auto_bind.cpp 

build:
	verilator -Wall --trace --cc --exe --build sim_main.cpp top.v

run:
	make build && obj_dir/Vtop
