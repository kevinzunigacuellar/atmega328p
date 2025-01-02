# Blink

Bare metal blink example for the ATmega328P microcontroller (Arduino UNO) using the avr-gcc toolchain.

## Installation

Run make to compile the code and generate the .hex file.

```bash
make
```

Upload the .hex file to the microcontroller using avrdude.

```bash
make flash
```