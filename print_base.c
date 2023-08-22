#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * print_bin - a function that convert a int to bin
 * @args : argument
 * Return: int number of printed char
 */
int print_bin(va_list args)
{
	char *ptr, *rev_ptr;
	unsigned int i = 0, r = 0, q;
	int count;
	unsigned int dec = va_arg(args, unsigned int);

	if (dec == 0)
		return (_putchar('0'));
	ptr = malloc(sizeof(char) * (nod_by_base(dec, 2) + 1));
	if (ptr == NULL)
		return (-1);

	q = dec;
	while (q > 0)
	{
		r = q % 2;
		if (r == 0)
			ptr[i] = '0';
		else
			ptr[i] = '1';
		q /= 2;
		i++;
	}
	ptr[i] = '\0';
	rev_ptr = rev_str(ptr);
	count = write(1, rev_ptr, _strlen(rev_ptr));
	free(rev_ptr);
	free(ptr);
	return (count);
}
