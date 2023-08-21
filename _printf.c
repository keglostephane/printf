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
	fspec chartof[] = {{'c', print_char}, {'s', print_str}, {'\0', NULL}};
	va_list args;

	va_start(args, format);
	i = 0, p = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = 0;
			while (chartof[j].c)
			{
				if (format[i + 1] == chartof[j].c)
				{
					p += chartof[j].func(args);
					break;
				}
				if (format[i + 1] == '%')
				{
					p += _putchar(format[i + 1]);
					break;
				}
				j++;
			}
			if (!format[i + 1])
				break;
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
