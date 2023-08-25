#include "main.h"
#include <stdlib.h>

/**
 * print_S - prints a string with \x + hexa Upper
 * of non printable characters
 *
 * @args: list of variable arguments
 *
 * @buffer: buffer to store result before printing
 *
 * Return: the number of printed characters
 */
int print_S(va_list args, char *buffer)
{
	int i, j = 0;
	char *str = va_arg(args, char *);
	int count = 0;

	for (i = 0; i < _strlen(str); i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += flush_buffer(buffer);
			j = 0;
			count += _putchar(92);
			count += _putchar('x');
			if (str[i] < 16)
			{
				count += _putchar(48);
				count += print_hexa_up2(str[i], buffer);
			}
			else
				count += print_hexa_up2(str[i], buffer);
		}
		else
		{
			buffer[j] = str[i];
			j++;
		}
	}
	count += flush_buffer(buffer);
	return (count);
}
/**
 * print_hexa_up2 - print an integer in hexadecimal base in uppercase
 *
 * @dec: given int to convert
 *
 * @buffer: store the converted number in hexadecimal base
 *
 * Return: number of digits of the converted integer
 */
int print_hexa_up2(unsigned long dec, char *buffer)
{
	char *ptr, *rev_ptr;

	if (dec < 10)
		return (_putchar(dec + '0'));
	if (dec > 9 && dec < 16)
		return (_putchar(dec + 55));

	rev_ptr = store_base_reverse(dec, 16, 1, buffer);
	ptr = rev_str(rev_ptr);

	return (flush_buffer(ptr));
}
