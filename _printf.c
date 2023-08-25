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
	char buffer[SIZE] = {0};
	fspec chartof[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_modulo},
		{'d', print_int}, {'i', print_int}, {'b', print_bin},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexa},
		{'X', print_hexa_up}, {'r', print_rev_str}, {'R', print_rot13},
		{'S', print_S}, {'\0', NULL}};
	fspec *ptr = chartof;
	va_list args;

	va_start(args, format);
	i = 0, p = 0;

	if (!format)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = search_spec_to_print(format, i, &p, ptr, args,
						 buffer);
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
