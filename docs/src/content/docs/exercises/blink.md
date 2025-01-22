---
title: Blinking LED
description: Blink an LED on and off
---

The most basic program you can write for a microcontroller is to blink an LED on and off. This exercise demonstrates how to configure your development environment and write a simple program to blink an LED using the ATmega328P microcontroller.

## Introduction

The ATmega328P microcontroller has 32 general-purpose I/O pins that can be configured as inputs or outputs. To blink an LED, you need to set a pin as an output and toggle its state between high and low. You can achieve this by writing to the Data Direction Register (DDR) to set the pin as an output and writing to the Port Register (PORT) to toggle the pin state.

In this example, port B pin 5 (PB5) is connected to the built-in LED on the Arduino Uno board, allowing you to control the LED by writing to the DDRB and PORTB registers.

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0x04 (0x24) | DDRB7 | DDRB6 | DDRB5 | DDRB4 | DDRB3 | DDRB2 | DDRB1 | DDRB0 |
| Read/Write | R/W | R/W | R/W | R/W | R/W | R/W | R/W | R/W |
| Initial Value | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

The DDRB register controls the direction of the pins on port B, where setting a bit to 1 configures the corresponding pin as an output. The PORTB register controls the state of the pins on port B, where setting a bit to 1 turns the corresponding pin high (on) and setting it to 0 turns the pin low (off).





## Code

```c
#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void) {
  /* set pin 5 of PORTB for output*/
  DDRB = DDRB | (1 << DDB5);

  while (1) {
    /* set pin 5 high to turn led on */
    PORTB = PORTB | (1 << PORTB5);
    _delay_ms(BLINK_DELAY_MS);

    /* set pin 5 low to turn led off */
    PORTB = PORTB & ~(1 << PORTB5);
    _delay_ms(BLINK_DELAY_MS);
  }
}

```

## Further reading

- Read [about reference](https://diataxis.fr/reference/) in the Diátaxis framework
