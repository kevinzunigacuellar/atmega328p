---
title: Getting started
description: Learn the fundamentals of ATmega328P microcontroller programming
---

The ATmega328P is a versatile 8-bit microcontroller from Microchip Technology, widely recognized for its balance of performance, power efficiency, and ease of use. Built on the AVR architecture, it features a rich instruction set and a robust design tailored for embedded systems and hobbyist applications. 

To simplify getting started with the ATmega328P, instead of wiring the microcontroller to a breadboard we recommend using a development board like the Arduino Uno. This way, you can focus on learning the basics of programming and interfacing with the microcontroller without worrying about the hardware setup.

## Prerequisites

Before you begin, make sure you have the following:

- An Arduino Uno board
- A USB cable to connect the Arduino Uno to your computer
- VSCode or any other text editor of your choice
- Basic knowledge of C programming

## Installation

Using homebrew, install the avr-gcc toolchain:

```zsh
brew tap osx-cross/avr
brew install avr-gcc avrdude avr-binutils
```

This command installs three specific tools from the osx-cross/avr tap:

- `avr-gcc`: This is the GNU Compiler Collection tailored for AVR microcontrollers. It allows you to compile C or C++ code into machine code that can run on AVR devices.
- `avrdude`: This is a utility for uploading compiled programs to AVR microcontrollers. It's used to communicate with the microcontroller through various interfaces (e.g., USB or serial).
- `avr-binutils`: These are essential binary utilities (like assembler, linker, and object file manipulation tools) designed for AVR development. They work alongside `avr-gcc` to process and link your code.

## VSCode

To configure VSCode for AVR development, add the following settings to your `.vscode/c_cpp_properties`

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

This configuration tells VSCode where to find the AVR libraries and includes the necessary paths for the ATmega328P microcontroller.