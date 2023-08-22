#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct fspecifiers - maps format specifiers to functions
 *
 * @c: format specifier
 *
 * @func: function mapped to a format specifer
 *
 */
struct fspecifiers
{
	char c;
	int (*func)(va_list);
};

typedef struct fspecifiers fspec;

int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_char(va_list args);
int print_str(va_list args);
int print_modulo(va_list args);
int print_int(va_list args);
#endif
