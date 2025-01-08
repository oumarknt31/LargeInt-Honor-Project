# Large Number Arithmetic Using Doubly Linked List (Honor's)

## Overview

This project implements the `LargeInt` class in C++ to handle arithmetic operations on very large integers that exceed the size limit of primitive data types. It uses a **doubly linked list** as the underlying data structure to store individual digits of large integers. This enables the representation and manipulation of arbitrarily large numbers, which can be **positive**, **negative**, or **zero**.

## Features

The `LargeInt` class provides the following:

- **Dynamic Storage**: Uses a doubly linked list to store individual digits of the integer.
- **Encapsulation**: A fully encapsulated class design for easy integration and reuse.
- **Arithmetic Operations**: Support for operations such as addition, subtraction, multiplication, division, and modulus.
- **Relational Operators**: Includes comparison operators for equality and inequality.
- **Stream Operators**: Overloads input (`>>`) and output (`<<`) operators for convenient I/O.

## Key Functionalities

### Constructors
- **Default Constructor**: Initializes a `LargeInt` object to zero.

### Overloaded Operators
The following operators are overloaded for `LargeInt`:

1. **Arithmetic Operators**:
   - `+`: Addition
   - `-`: Subtraction
   - `*`: Multiplication
   - `/`: Division
   - `%`: Modulus

2. **Relational Operators**:
   - `==`: Equal to
   - `<`: Less than
   - `<=`: Less than or equal to
   - `>`: Greater than
   - `>=`: Greater than or equal to

3. **Stream Operators**:
   - `<<`: Output stream operator for printing `LargeInt` values.
   - `>>`: Input stream operator for reading `LargeInt` values.
