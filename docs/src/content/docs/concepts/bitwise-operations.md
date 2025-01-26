---
title: Bitwise Operations
description: Learn how to manipulate individual bits in binary numbers using bitwise operators in C programming.
---

Bitwise operators are used to perform operations on individual bits of binary numbers. They are commonly used in low-level programming to manipulate hardware registers and control specific bits.

## Shift Left (`<<`):

Shifts the bits of a number to the left by a specified number of positions. It is mostly used to set specific bits.

```c
a = 1;          // 0b00000001 (1)
b = a << 3;     // 0b00001000 (8)
```

## NOT (`~`):

Inverts all the bits of a number. It is mostly used to create a bitmask to clear specific bits.

```c
a = 0b00000001; // 0b00000001 (1)
b = ~a;         // 0b11111110 (-2)
```

## OR (`|`):

Compares each bit of two numbers and returns a new number where each bit is set to 1 if either bit is 1, otherwise 0. It is mostly used to set specific bits.

For example we would like to set Bit 5 of PORTB

```c
DDRB = DDRB | (1 << 5);
```
Assuming DDRB = 0b00000000, the result will be:

```txt
b00000000   [original PORTB]
b00100000   [bitmask: (1 << 5)]
---------
b00100000   (result, bit 5 is set to 1)
```

## AND (`&`):

Compares each bit of two numbers and returns a new number where each bit is set to 1 only if both bits are 1, otherwise 0. It is mostly used to clear specific bits.

For example we would like to clear Bit 5 of PORTB

```c
DDRB = DDRB & ~(1 << 5);
```

Assuming DDRB = 0b00100000, the result will be:

```txt
b00100000   [original PORTB]
b11011111   [bitmask: ~(1 << 5)]
---------
b00000000   (result, bit 5 is set to 0)
```

## XOR (`^`):

Compares each bit of two numbers and returns a new number where each bit is set to 1 only if one of the bits is 1, otherwise 0. It is mostly used to toggle specific bits.

For example we would like to toggle Bit 5 of PORTB

```c
DDRB = DDRB ^ (1 << 5);
```

Assuming DDRB = 0b00100000, the result will be:

```txt
b00100000   [original PORTB]
b00100000   [bitmask: (1 << 5)]
---------
b00000000   (result, bit 5 is toggled)
```