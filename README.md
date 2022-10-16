# Printf

This project serves only as an education purpose. It is an attempt to implement the `printf` function from
C standard library using only the following functions:

* `write` man 2 write
* `malloc` man 3 malloc
* `free` man 3 free
* `va_start` man 3 va_start
* `va_end` man 3 va_end
* `va_copy` man 3 va_copy
* `va_arg` man 3 va_arg

## Description

`printf` stands for print formatted. It is a function of C standard library used to send formatted output
to stdout. it's defined in the `stdio.h` header file.

## Prototype

`int _printf(const char *format, ...);

## Compilation

C sources files are compiled on Ubuntu 20.O4 LTS using gcc :

`$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c`