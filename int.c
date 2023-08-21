#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_int - a function that print an int
 * @args: arguments
 * Return: int (number of digits printed)
 */
int print_int(va_list args)
{
	int n_10 = 1; /*n_10 : number of iterations by dividing by 10 */
	int digit, acc = 0;

	unsigned int n;
	int nop = va_arg(args, int);

	if (nop < 0)
	{
		acc += _putchar(45);
		n = (-1) * nop;
	}
	else
		n = nop;
	while (n / n_10 > 9)
		n_10 *= 10;
	while (n_10 > 0)
	{
		digit = n / n_10;
		acc += _putchar(digit + '0');
		n = n - (n_10 * digit);
		n_10 /= 10;
	}
	return (acc);
}
