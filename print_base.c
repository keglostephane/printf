#include "main.h"
#include <stdlib.h>

/**
 * print_bin - a function that convert a int to bin
 *
 * @args : argument
 *
 * @buffer: buffer to store result before printing
 *
 * Return: int number of printed char
 */
int print_bin(va_list args, char *buffer)
{
	char *ptr, *rev_ptr;
	unsigned long dec;

	dec = va_arg(args, unsigned long);

	if (dec < 2)
		return (_putchar(dec + '0'));

	rev_ptr = store_base_reverse(dec, 2, 0, buffer);
	ptr = rev_str(rev_ptr);

	return (flush_buffer(ptr));
}


/**
 * print_octal - print an integer in octal base
 *
 * @args: list of variable arguments
 *
 * @buffer: store the converted number in octal base
 *
 * Return: number of digits of the converted integer
 */
int print_octal(va_list args, char *buffer)
{
	char *ptr, *rev_ptr;
	unsigned long dec;

	dec = va_arg(args, unsigned long);

	if (dec < 8)
		return (_putchar(dec + '0'));

	rev_ptr = store_base_reverse(dec, 8, 0, buffer);
	ptr = rev_str(rev_ptr);

	return (flush_buffer(ptr));
}

/**
 * print_unsigned - print an unsigned integer
 *
 * @args: list of variable arguments
 *
 * @buffer: store the unsigned number
 *
 * Return: number of digits of the unsigned integer
 */
int print_unsigned(va_list args, char *buffer)
{
	char *ptr, *rev_ptr;
	unsigned long dec;

	dec = va_arg(args, unsigned long);

	if (dec < 10)
		return (_putchar(dec + '0'));

	rev_ptr = store_base_reverse(dec, 10, 0, buffer);
	ptr = rev_str(rev_ptr);

	return (flush_buffer(ptr));
}

/**
 * print_hexa - print an integer in hexadecimal base
 *
 * @args: list of variable arguments
 *
 * @buffer: store the converted number in hexadecimal base
 *
 * Return: number of digits of the converted integer
 */
int print_hexa(va_list args, char *buffer)
{
	char *ptr, *rev_ptr;
	unsigned long dec;

	dec = va_arg(args, unsigned long);

	if (dec < 10)
		return (_putchar(dec + '0'));
	if (dec > 9 && dec < 16)
		return (_putchar(dec + 87));

	rev_ptr = store_base_reverse(dec, 16, 0, buffer);
	ptr = rev_str(rev_ptr);

	return (flush_buffer(ptr));
}

/**
 * print_hexa_up - print an integer in hexadecimal base in uppercase
 *
 * @args: list of variable arguments
 *
 * @buffer: store the converted number in hexadecimal base
 *
 * Return: number of digits of the converted integer
 */
int print_hexa_up(va_list args, char *buffer)
{
	char *ptr, *rev_ptr;
	unsigned long dec;

	dec = va_arg(args, unsigned long);

	if (dec < 10)
		return (_putchar(dec + '0'));
	if (dec > 9 && dec < 16)
		return (_putchar(dec + 87));

	rev_ptr = store_base_reverse(dec, 16, 1, buffer);
	ptr = rev_str(rev_ptr);

	return (flush_buffer(ptr));
}
