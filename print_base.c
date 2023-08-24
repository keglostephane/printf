#include "main.h"
#include <stdlib.h>

/**
 * store_base_reverse - store a number converted in a base in reverse
 *
 * @n: number to convert in base
 *
 * @base: the base to convert to
 *
 * @upper: flag for printing in upper case for base greater than 10
 *
 * @buffer: buffer to store result before printing
 *
 * Return: the buffer that contain the number converted in base
 * stored in reverse
 *
 */

char *store_base_reverse(unsigned int n, int base, int upper,
			 char *buffer)
{
	int i, r;

	i = 0;
	while (n > 0)
	{
		r = n % base;
		if (r < 10)
			buffer[i++] = r + '0';
		else
		{
			if (upper)
				buffer[i++] = r + 55;
			else
				buffer[i++] = r + 87;
		}
		n /= base;
	}

	return (buffer);
}

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
