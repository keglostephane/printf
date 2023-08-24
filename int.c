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
