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

<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 320 240"><path stroke="currentColor" stroke-linecap="square" stroke-width="2" d="M220 40h40M220 40v8"/><path fill="none" stroke="currentColor" stroke-linecap="square" stroke-width="2" d="M212 48h16l-8 8-8-8Z"/><path stroke="currentColor" stroke-linecap="square" stroke-width="2" d="M260 40v15M260 95v15"/><path fill="none" stroke="currentColor" stroke-linecap="square" stroke-width="2" d="M260 55v2l-7 3 14 6-14 6 14 6-14 6 14 6-7 3v2"/><text fill="currentColor" x="246" y="75" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">220 Ω</text><path stroke="currentColor" stroke-linecap="square" stroke-width="2" d="M150 160h110M260 150v10M150 160v10"/><path fill="none" stroke="currentColor" stroke-width="2" d="M25 25h120v195H25z"/><text fill="currentColor" x="61" y="55" dominant-baseline="middle" font-family="Arial" font-size="11">ARDUINO</text><text fill="currentColor" x="68" y="65" dominant-baseline="middle" font-family="Arial" font-size="11">UNO r3</text><path stroke="currentColor" stroke-linecap="square" stroke-width="2" d="M20 80h5M20 90h5M20 100h5M20 110h5M20 120h5M20 130h5M20 140h5M20 160h5M20 170h5M20 180h5M20 190h5M20 200h5M20 210h5M145 50h5M145 60h5M145 70h5M145 80h5M145 90h5M145 100h5M145 110h5M145 120h5M145 140h5M145 150h5M145 160h5M145 170h5M145 180h5M145 190h5M145 200h5M145 210h5"/><text fill="currentColor" x="29" y="80" dominant-baseline="middle" font-family="Arial" font-size="11">IOREF</text><text fill="currentColor" x="29" y="90" dominant-baseline="middle" font-family="Arial" font-size="11">RESET</text><text fill="currentColor" x="29" y="100" dominant-baseline="middle" font-family="Arial" font-size="11">3.3V</text><text fill="currentColor" x="29" y="110" dominant-baseline="middle" font-family="Arial" font-size="11">5V</text><text fill="currentColor" x="29" y="120" dominant-baseline="middle" font-family="Arial" font-size="11">GND</text><text fill="currentColor" x="29" y="130" dominant-baseline="middle" font-family="Arial" font-size="11">GND</text><text fill="currentColor" x="29" y="140" dominant-baseline="middle" font-family="Arial" font-size="11">Vin</text><text fill="currentColor" x="29" y="160" dominant-baseline="middle" font-family="Arial" font-size="11">A0</text><text fill="currentColor" x="29" y="170" dominant-baseline="middle" font-family="Arial" font-size="11">A1</text><text fill="currentColor" x="29" y="180" dominant-baseline="middle" font-family="Arial" font-size="11">A2</text><text fill="currentColor" x="29" y="190" dominant-baseline="middle" font-family="Arial" font-size="11">A3</text><text fill="currentColor" x="29" y="200" dominant-baseline="middle" font-family="Arial" font-size="11">A4</text><text fill="currentColor" x="29" y="210" dominant-baseline="middle" font-family="Arial" font-size="11">A5</text><text fill="currentColor" x="141" y="50" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">AREF</text><text fill="currentColor" x="141" y="60" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">GND</text><text fill="currentColor" x="141" y="70" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">D13</text><text fill="currentColor" x="141" y="80" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">D12</text><text fill="currentColor" x="141" y="90" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">PWM D11</text><text fill="currentColor" x="141" y="100" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">PWM D10</text><text fill="currentColor" x="141" y="110" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">PWM   D9</text><text fill="currentColor" x="141" y="120" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">D8</text><text fill="currentColor" x="141" y="140" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">D7</text><text fill="currentColor" x="141" y="150" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">PWM   D6</text><text fill="currentColor" x="141" y="160" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">PWM   D5</text><text fill="currentColor" x="141" y="170" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">D4</text><text fill="currentColor" x="141" y="180" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">PWM   D3</text><text fill="currentColor" x="141" y="190" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">D2</text><text fill="currentColor" x="141" y="200" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">TX   D1</text><text fill="currentColor" x="141" y="210" dominant-baseline="middle" font-family="Arial" font-size="11" text-anchor="end">RX   D0</text><path fill="none" stroke="currentColor" stroke-linecap="square" stroke-width="2" d="M85 40c2 9 15 9 15 0s-13-9-15 0M85 40c-2-9-15-9-15 0s13 9 15 0"/><path stroke="currentColor" stroke-linecap="square" stroke-width="2" d="M91 40h4M93 42v-4M79 40h-4M260 150v-40"/><path fill="none" stroke="currentColor" stroke-linecap="square" stroke-width="2" d="M252 123h16m-8 0 8 15h-16l8-15M271 127l8-8m1-1-2 4-2-2 4-2-2 4M264 121l8-8m1-1-2 4-2-2 4-2-2 4"/><circle cx="150" cy="160" r="2" stroke="currentColor" stroke-width="2"/></svg>


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