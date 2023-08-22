#include "main.h"

/**
 * print_char - prints a character
 *
 * @args: list of variable arguments
 *
 * Return: Always 1 in success
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_str - prints a string
 *
 * @args: list of variable arguments
 *
 * Return: the number of characters printed
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);

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
 * Return: Always 1 on success
 */
int print_modulo(va_list args)
{
	char c = '%';

	(void)args;
	write(1, &c, 1);
	return (1);
}

/**
 * ignore_space_after_percent - traverse a string until a given position
 *
 * @format: string to traverse
 *
 * @index: current position in the string
 *
 * Return: the position before the first character that is not a space
 *
 */
int ignore_space_after_percent(const char *format, int index)
{
	int i = 0;

	if (format)
	{
		while (format[index + i] == ' ')
			i++;
	}

	return (index + i - 1);
}
