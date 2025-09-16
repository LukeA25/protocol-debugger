TARGET = blink
OBJS = crt0.o main.o

CFLAGS = -Wall -O2 -ffreestanding -nostdlib -mcpu=cortex-m0plus -mthumb
LDFLAGS = -Tlink.ld -nostdlib -ffreestanding -Wl,--gc-sections

all: $(TARGET).elf

%.o: %.c
	arm-none-eabi-gcc $(CFLAGS) -c $< -o $@

%.o: %.S
	arm-none-eabi-gcc $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJS)
	arm-none-eabi-gcc $(LDFLAGS) $(OBJS) -o $@

clean:
	rm -f *.o *.elf
