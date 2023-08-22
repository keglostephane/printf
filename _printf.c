#include "main.h"

/**
 * _printf - produces output according to a format
 *
 * @format: const pointer to constant string
 *
 * Return:  the number of characters printed
 */
int _printf(const char * const format, ...)
{
	int i, j, p;
	fspec chartof[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_modulo},
		{'d', print_int}, {'i', print_int}, {'b', print_bin},
		{'\0', NULL}};
	va_list args;

	va_start(args, format);
	i = 0, p = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = 0;
			if (format[i + 1] == ' ')
				i = ignore_space_after_percent(
					format + i, i + 1);
			while (chartof[j].c)
			{
				if (format[i + 1] == chartof[j].c)
				{
					p += chartof[j].func(args);
					break;
				}
				j++;
			}
			if (format[i + 1] == '\0')
				return (-1);
			if (!chartof[j].c)
				p += write(1, (void *)(format + i), 2);
			i++;
		}
		else
			p += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (p);
}
