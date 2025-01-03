# Interrupt

Bare metal button LED example for the ATmega328P microcontroller. the LED is toggled when the button is pressed.

## Circuit

The button is connected to pin 2 of the microcontroller. The initial state of the pin is high. When the button is pressed, the pin is pulled low. The LED is connected to pin 13 (Built-in LED) of the microcontroller.


## Installation

Run make to compile the code and generate the .hex file.

```bash
make
```

Upload the .hex file to the microcontroller using avrdude.

```bash
make flash
```
