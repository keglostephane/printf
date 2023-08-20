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
