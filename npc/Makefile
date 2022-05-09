BUILD_DIR = ./build

test:
	mill -i __.test

run:
	$(call git_commit, "generate verilog")
	mkdir -p $(BUILD_DIR)
	mill -i __.test.runMain Elaborate -td $(BUILD_DIR)

clean:
	-rm -rf $(BUILD_DIR)

.PHONY: test run clean

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."

include ../Makefile
