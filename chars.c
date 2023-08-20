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
