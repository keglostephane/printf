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
	char *str, *ptr;
	(void)buffer;

	str = va_arg(args, char *);

	if (str == NULL)
		return (-1);

	ptr = malloc(sizeof(char) * _strlen(str));

	if (!ptr)
		return (-1);

	return (flush_buffer(rev_str(_memcpy(ptr, str, _strlen(str)))));
}
