#ifndef MAIN_H
#define MAIN_H

#define SIZE 1024
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>

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
	int (*func)(va_list, char *);
};

typedef struct fspecifiers fspec;

int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *s);
int nod_by_base(unsigned int n, unsigned int base);
char *rev_str(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
char *reverse_str(char *s);
int print_char(va_list args, char *buffer);
int print_str(va_list args, char *buffer);
int print_rev_str(va_list args, char *buffer);
int print_modulo(va_list args, char *buffer);
int print_int(va_list args, char *buffer);
int print_bin(va_list args, char *buffer);
int print_S(va_list args, char *buffer);
int print_octal(va_list args, char *buffer);
int print_unsigned(va_list args, char *buffer);
int print_hexa(va_list args, char *buffer);
int print_hexa_up(va_list args, char *buffer);
int print_hexa_up2(unsigned long dec, char *buffer);
int search_spec_to_print(const char *format, int i, int *counter,
			 fspec *chartof, va_list args, char *buffer);
char *store_base_reverse(unsigned int n, int base, int upper,
			 char *buffer);
int flush_buffer(char *buffer);
int print_rot13(va_list args, char *buffer);
int print_addr(va_list args, char *buffer);
#endif
