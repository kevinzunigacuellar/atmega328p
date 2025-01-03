# Device configuration
MCU = atmega328p
F_CPU = 16000000UL

# Build tools and flags
CC = avr-gcc
OBJCOPY = avr-objcopy
SIZE = avr-size
CFLAGS = -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)

# Directory structure
BUILD_DIR = build
SRC_DIR = src
$(shell mkdir -p $(BUILD_DIR))

# Project configuration
TARGET = firmware
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Upload configuration (for Arduino Uno)
PROGRAMMER = arduino
BAUDRATE = 115200
PORT = /dev/tty.usbmodem*

# build the program
all: $(BUILD_DIR)/$(TARGET).hex size

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/$(TARGET).hex: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

size: $(BUILD_DIR)/$(TARGET).elf
	$(SIZE) --format=avr --mcu=$(MCU) $<

flash: $(BUILD_DIR)/$(TARGET).hex
	avrdude -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUDRATE) -U flash:w:$<

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all flash clean
