#include "main.h"
#include <stdlib.h>

/**
 * print_char - prints a character
 *
 * @args: list of variable arguments
 *
 * @buffer: buffer to store result before printing
 *
 * Return: Always 1 in success
 */
int print_char(va_list args, char *buffer)
{
	(void)buffer;
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_str - prints a string
 *
 * @args: list of variable arguments
 *
 * @buffer: buffer to store result before printing
 *
 * Return: the number of characters printed
 */
int print_str(va_list args, char *buffer)
{
	char *str = va_arg(args, char *);
	(void)buffer;

	if (!str)
	{
		str = "(null)";
		write(1, str, _strlen(str));
		return (_strlen(str));
	}
	else
		write(1, str, _strlen(str));

	return (_strlen(str));
}
/**
 * print_modulo - print the % charater if the previous one was %
 *
 * @args : list of variable arguments
 *
 * @buffer: buffer to store result before printing
 *
 * Return: Always 1 on success
 */
int print_modulo(va_list args, char *buffer)
{
	char c = '%';

	(void)args;
	(void)buffer;

	write(1, &c, 1);
	return (1);
}

/**
 * print_rev_str - prints a string in reverse
 *
 * @args: list of variable arguments
 *
 * @buffer: buffer to store result before printing
 *
 * Return: number of characters of the reversed string
 */
int print_rev_str(va_list args, char *buffer)
{
	char *str;

	str = va_arg(args, char *);

	if (str == NULL)
		return (-1);

	_memcpy(buffer, str, _strlen(str));

	return (flush_buffer(rev_str(buffer)));
}
/**
 * print_rot13 - a program that encrypt the input string
 * by rot13 algorithm
 * @args: arguments
 * @buffer : buffer sized 1024
 * Return: the number of char printed
 */
int print_rot13(va_list args, char *buffer)
{
	char *arg = va_arg(args, char *);
	int i, j;
	char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
			'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
			'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
			'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	char rot13[] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
			'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
			'j', 'k', 'l', 'm', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
			'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E',
			'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};
	i = 0;
	j = 0;
	while (arg[i] != '\0')
	{
		j = 0;
		while (j < 52)
		{
			if (arg[i] == alpha[j])
			{
				buffer[i] = rot13[j];
				break;
			}
			j++;
			if (j == 52)
				buffer[i] = arg[i];
		}
		i++;
	}
	buffer[i] = '\0';
	return (flush_buffer(buffer));
}
