---
title: Getting started
description: Learn the fundamentals of ATmega328P microcontroller programming
---

The ATmega328P is a versatile 8-bit microcontroller from Microchip Technology, widely recognized for its balance of performance, power efficiency, and ease of use. Built on the AVR architecture, it features a rich instruction set and a robust design tailored for embedded systems and hobbyist applications.

To simplify getting started with the ATmega328P, we recommend using a development board like the Arduino Uno instead of wiring the microcontroller directly to a breadboard. This allows you to focus on learning the basics of programming and interfacing with the microcontroller without worrying about the hardware setup.

## Prerequisites

Before you begin, ensure you have the following:

- An Arduino Uno board
- A USB cable to connect the Arduino Uno to your computer
- VSCode or another text editor of your choice
- Basic knowledge of C programming

## Installation

To set up your development environment, use Homebrew to install the AVR-GCC toolchain. Run the following commands:

```zsh
tap osx-cross/avr
brew install avr-gcc avrdude avr-binutils
```

This installs the following tools:

- **`avr-gcc`**: The GNU Compiler Collection tailored for AVR microcontrollers, allowing you to compile C or C++ code into machine code for AVR devices.
- **`avrdude`**: A utility for uploading compiled programs to AVR microcontrollers, facilitating communication through interfaces such as USB or serial.
- **`avr-binutils`**: Essential binary utilities (assembler, linker, and object file manipulation tools) designed for AVR development, complementing `avr-gcc` to process and link your code.

## Configuring VSCode

To configure VSCode for AVR development, add the following settings to your `.vscode/c_cpp_properties.json` file:

```json title=".vscode/c_cpp_properties.json"
{
  "configurations": [
    {
      "name": "Mac",
      "includePath": [
        "${workspaceFolder}/src/**",
        "/usr/local/Cellar/avr-gcc/*/lib/avr-gcc/*/avr/include"
      ],
      "defines": ["__AVR_ATmega328P__"],
      "compilerPath": "/opt/homebrew/bin/avr-gcc"
    }
  ],
  "version": 4
}
```

This configuration specifies where VSCode can find the AVR libraries and includes the necessary paths for the ATmega328P microcontroller.
