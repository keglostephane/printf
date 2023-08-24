#include "main.h"

/**
 * nod_by_base - a function that calculate the number of
 * digit needed to print the given int in a specific base
 * @n: unsigned int
 * @base: unsigned int
 * Return: int
 */
int nod_by_base(unsigned int n, unsigned int base)
{
	unsigned int i;

	for (i = 0; n > 0; i++)
	{
		n /= base;
	}
	return (i);
}

/**
 * search_spec_to_print - search a valid specifier to use to print
 *
 * @format: string to search for a valid specifier
 *
 * @i: position of start of a specifier
 *
 * @counter: number of bytes already written to stdout
 *
 * @chartof: a structure that map characters to functions
 *
 * @args: variable argument
 *
 * @buffer: buffer to store result before printing
 *
 * Return: the current index in the structure `chartof`
 */
int search_spec_to_print(const char *format, int i, int *counter,
			      fspec *chartof, va_list args, char *buffer)
{
	int j;

	j = 0;
	while (chartof[j].c)
	{
		if (format[i + 1] == chartof[j].c)
		{
			*counter += chartof[j].func(args, buffer);
			break;
		}
		j++;
	}

	return (j);
}

/**
 * flush_buffer - send buffer content to stdout
 *
 * @buffer: a buffer that holds data
 *
 * Return: the number of bytes send to stdout
 */
int flush_buffer(char *buffer)
{
	int i, j;

	i = write(1, buffer, _strlen(buffer));

	for (j = 0; buffer[j] != '\0'; j++)
		buffer[j] = '\0';

	return (i);
}
