NAME    = blink
CPU     = cortex-m0plus
ARMGNU  = arm-none-eabi

AFLAGS  = --warn --fatal-warnings -mcpu=$(CPU) -g
CFLAGS  = -mcpu=$(CPU) -nostartfiles -ffreestanding -g -O0 -fpic -mthumb -Iinclude
LDFLAGS = -nostdlib

SRCS    = main.c src/gpio.c
OBJS    = $(SRCS:.c=.o)
PICOSDK = ../external/pico-sdk
PICOTOOL = ../external/picotool/build

all: $(NAME).bin

crt0.o: crt0.s
	$(ARMGNU)-as $(AFLAGS) crt0.s -o crt0.o

%.o: %.c
	$(ARMGNU)-gcc $(CFLAGS) -c $< -o $@

$(NAME).bin: link.ld crt0.o $(OBJS)
	$(ARMGNU)-ld $(LDFLAGS) --entry 0x20040001 -T link.ld crt0.o $(OBJS) -o $(NAME).elf
	$(ARMGNU)-objdump -D $(NAME).elf > $(NAME).list
	$(ARMGNU)-objcopy -O binary $(NAME).elf $(NAME).bin
	$(PICOTOOL)/picotool uf2 convert $(NAME).bin $(NAME).uf2 -o 0x20040000 --family rp2040

clean: 
	rm -f *.bin *.o *.elf *.list *.uf2
