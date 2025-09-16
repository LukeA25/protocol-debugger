# === Config ===
TARGET = blink
OBJS = crt0.o main.o

CFLAGS = -Wall -O2 -ffreestanding -nostdlib -mcpu=cortex-m0plus -mthumb
LDFLAGS = -Tlink.ld -nostdlib -ffreestanding -Wl,--gc-sections

PICOTOOL = ../external/picotool/build/picotool

# === Default Target ===
all: $(TARGET).uf2

# === Compilation Rules ===
%.o: %.c
	arm-none-eabi-gcc $(CFLAGS) -c $< -o $@

%.o: %.S
	arm-none-eabi-gcc $(CFLAGS) -c $< -o $@

# === Link to ELF ===
$(TARGET).elf: $(OBJS)
	arm-none-eabi-gcc $(LDFLAGS) $(OBJS) -o $@

# === Convert ELF to UF2 using picotool ===
%.uf2: %.elf
	@if [ ! -f $(PICOTOOL) ]; then \
		echo "Error: picotool is not built. Please run:"; \
		echo "  cd external/picotool && mkdir build && cd build && cmake .. && make"; \
		exit 1; \
	fi
	$(PICOTOOL) uf2 convert $< $@

# === Flash to Pico ===
flash: $(TARGET).uf2
	$(PICOTOOL) load $(TARGET).uf2 --family rp2040 --reboot

# === Clean ===
clean:
	rm -f *.o *.elf *.uf2
