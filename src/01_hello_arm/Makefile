CROSS_COMPILE = arm-linux-gnueabihf
# Platform: ARM Cortex-M3
arch    ?= arm
CC      := $(CROSS_COMPILE)-gcc
# CC      := arm-linux-gnueabihf-gcc-5
LD      := $(CROSS_COMPILE)-ld
OBJCOPY := $(CROSS_COMPILE)-objcopy
DD      := $(CROSS_COMPILE)-dd
#QEMU    := qemu-system-arm
QEMU    := qemu-arm-static
GDB     := gdb

CFLAGS := -static -Wall -fno-stack-protector


.PHONY: build clean run 

asm_obj := $(patsubst src/%.s,\
	build/arch/$(arch)/%.o, $(wildcard src/*.s))

build/arch/$(arch)/%.o : src/%.s
	mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $< -o $@  



run: $(asm_obj)
	@echo "result:"
	@$(QEMU) $(asm_obj)

qemu: $(asm_obj)
	@#qemu-system-arm  -machine lm3s811evb -kernel kernel.elf
	@echo "result:"
	@$(QEMU) $(asm_obj)

build: 
	$(CC) $(CFLAGS) src/hello_arm.s -o $(asm_obj)

clean:
	@# rm -r build
	@if [ ! -d "build" ];then \
	echo "directory 'build' currently does NOT exist."; \
	else \
	rm -r build; \
	fi
