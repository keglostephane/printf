#include "main.h"

/**
 * print_int - a function that print an int
 *
 * @args: arguments
 *
 * @buffer: buffer to store result before printing
 *
 * Return: int (number of digits printed)
 */
int print_int(va_list args, char *buffer)
{
	int n_10 = 1; /*n_10 : number of iterations by dividing by 10 */
	int i, digit;
	unsigned int n;
	int nop = va_arg(args, int);

	i = 0;

	if (nop < 0)
	{
		buffer[i++] = '-';
		n = (-1) * nop;
	}
	else
		n = nop;

	while (n / n_10 > 9)
		n_10 *= 10;

	while (n_10 > 0)
	{
		digit = n / n_10;
		buffer[i++] = digit + '0';
		n = n - (n_10 * digit);
		n_10 /= 10;
	}

	return (flush_buffer(buffer));
}

/**
 * print_addr - prints a memory address
 *
 * @args: list of variable arguments
 *
 * @buffer: store the characters to print  in reverse order
 *
 * Return: the number of characters written to stdout
 */
int print_addr(va_list args, char *buffer)
{
	int i, r;
	uintptr_t n;
	void *ptr = va_arg(args, void *);

	if (!ptr)
		return (-1);

	n = (uintptr_t)(ptr);

	i = 0;
	while (n > 0)
	{
		r = n % 16;
		if (r < 10)
			buffer[i++] = r + '0';
		else
			buffer[i++] = r + 87;
		n /= 16;
	}
	i = _strlen(buffer);
	buffer[i] = 'x';
	buffer[i + 1] = '0';

	return (flush_buffer(rev_str(buffer)));
}
