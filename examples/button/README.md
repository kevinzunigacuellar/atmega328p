# Button

Bare metal button LED example for the ATmega328P microcontroller. When the button is pressed, the LED turns on. When the button is released, the LED turns off.

## Installation

Run make to compile the code and generate the .hex file.

```bash
make
```

Upload the .hex file to the microcontroller using avrdude.

```bash
make flash
```
