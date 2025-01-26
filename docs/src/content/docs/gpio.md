---
title: GPIO
description: A comprehensive guide to I/O ports and their configuration in the Arduino Uno.
---

The Arduino Uno provides input/output (I/O) ports that enable the microcontroller to interact with external devices such as sensors, motors, and LEDs. These ports are divided into digital pins and analog pins, grouped into internal ports for efficient control.

- **PORTB**: Controls digital pins D8 to D13.

  | Pin Number | Port Bit |
  | ---------- | -------- |
  | D8         | PB0      |
  | D9         | PB1      |
  | D10        | PB2      |
  | D11        | PB3      |
  | D12        | PB4      |
  | D13        | PB5      |

- **PORTC**: Controls analog pins A0 to A5.

  | Pin Number | Port Bit |
  | ---------- | -------- |
  | A0         | PC0      |
  | A1         | PC1      |
  | A2         | PC2      |
  | A3         | PC3      |
  | A4         | PC4      |
  | A5         | PC5      |

- **PORTD**: Controls digital pins D0 to D7.

  | Pin Number | Port Bit |
  | ---------- | -------- |
  | D0         | PD0      |
  | D1         | PD1      |
  | D2         | PD2      |
  | D3         | PD3      |
  | D4         | PD4      |
  | D5         | PD5      |
  | D6         | PD6      |
  | D7         | PD7      |

## Registers for I/O Control

Each port has three registers associated with it:

- **DDR (Data Direction Register)**: DDR controls the data direction (input or output). Set the corresponding bit to 1 for output and 0 for input.
- **PORT Register**: PORT controls the output state. Set the corresponding bit to 1 to set the pin HIGH and 0 to set it LOW. When configured as input, the PORT register can be used to enable pull-up resistors. To enable pull-up resistors, set the corresponding bit to 1.
- **PIN Register**: PIN reads the current state of the input pins.

For example, if you would like to configure pin D8 (PB0) as an output and set it HIGH, you can use the following code:

```c
DDRB |= (1 << PB0); // Set D8 (PB0) as output
PORTB |= (1 << PB0); // Set D8 (PB0) HIGH
```

:::note[Bitwise operators]
The bitwise operators `|`, `^`, and `<<` are used to manipulate individual bits in the registers. If you are not familiar with them, read the [bitwise operators section](/concepts#bitwise-operators).
:::

## Blinking an LED

A more elaborated example is to blink an LED connected to pin D5. Before diving into the code, let's first understand the registers involved:

- **DDRB**: Data Direction Register for PORTB. Setting bit 5 (PB5) to 1 configures pin D5 as an output.
- **PORTB**: Port Register for PORTB. Setting bit 5 (PB5) to 1 turns the LED on, while clearing it (setting to 0) turns the LED off.

### Circuit Setup

Connect an LED to pin D5 with a current-limiting resistor. Assuming that the diode forward voltage is 2V and the current is 20mA, you can use a 220Ω resistor or higher.

### Code

This code snippet configures pin D5 as an output and toggles the pin state to blink the LED. The `_delay_ms` function imported from `utils/delay.h` is used to introduce a delay between turning the LED on and off. `avr/io.h` is included to access the I/O registers and macros.

```c
#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void) {
  /* set pin 5 of PORTB for output */
  DDRB |= (1 << DDB5);

  while (1) {
    /* toggle pin 5 to turn LED on/off */
    PORTB ^= (1 << PORTB5);
    _delay_ms(BLINK_DELAY_MS);
  }
}
```