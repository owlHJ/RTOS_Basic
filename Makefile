ARCH = armv7-a
MCPU = cortex-a8

TARGET = rvpb
ARM_ARCH = cortexAR

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-gcc
OC = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump

LINKER_SCRIPT = ./navilos.ld
MAP_FILE = build/navilos.map
SYM_FILE = build/navilos.sym

ASM_SRCS = $(wildcard boot/*.S)
ASM_OBJS = $(patsubst boot/%.S, build/%.os, $(ASM_SRCS))

VPATH = 	boot 		\
		hal/$(TARGET) 	\
		lib 		\
		lib/$(ARM_ARCH) 	\
		kernel

C_SRCS  = $(notdir $(wildcard boot/*.c))
C_SRCS += $(notdir $(wildcard hal/$(TARGET)/*.c))
C_SRCS += $(notdir $(wildcard lib/*.c))
C_SRCS += $(notdir $(wildcard lib/$(ARM_ARCH)/*.c))
C_SRCS += $(notdir $(wildcard kernel/*.c))

C_OBJS = $(patsubst %.c, build/%.o, $(sort $(C_SRCS)))

INC_DIRS =    -I boot          	\
              -I include       	\
              -I hal           	\
              -I hal/$(TARGET) 	\
              -I lib           	\
              -I lib/$(ARM_ARCH)\
              -I kernel

CFLAGS = -c -g -std=c11
LDFLAGS = -nostartfiles -nostdlib -nodefaultlibs -static -lgcc

navilos = build/navilos.axf
navilos_bin = build/navilos_bin

.PHONY: all clean run debug gdb

all: $(navilos)

clean:
	@rm -fr build
run: $(navilos)
	qemu-system-arm -M realview-pb-a8 -kernel $(navilos) -nographic
debug: $(navilos)
	qemu-system-arm -M realview-pb-a8 -kernel $(navilos) -nographic -S -gdb tcp::1234,ipv4
	
gdb:
	gdb-multiarch $(navilos)

kill:
	kill -9 `ps aux | grep 'qemu' | awk 'NR==1{print $$2}'`
	
$(navilos): $(ASM_OBJS) $(C_OBJS) $(LINKER_SCRIPT)
	$(LD) -n -T $(LINKER_SCRIPT) -o $(navilos) $(ASM_OBJS) $(C_OBJS) -Wl,-Map=$(MAP_FILE) $(LDFLAGS)
	$(OD) -t $(navilos) > $(SYM_FILE)
	$(OC) -O binary $(navilos) $(navilos_bin)

build/%.os: %.S
	mkdir -p $(shell dirname $@)
	$(CC) -march=$(ARCH) -mcpu=$(MCPU) $(INC_DIRS) $(CFLAGS) -o $@ $<

build/%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) -march=$(ARCH) -mcpu=$(MCPU) $(INC_DIRS) $(CFLAGS) -o $@ $<
