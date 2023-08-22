#include <unistd.h>
#include <stdlib.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - Entry point
 * Description:  a program that return the length of a given
 * char
 * @s: given char
 * Return: the number of characters
 */
int _strlen(char *s)
{
	int count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}
/**
 * *_memcpy - Entry point
 * Description: function copies n bytes from memory area
 * src to memory area dest
 * @dest : a pointer to a string(dest)
 * @src :a pointerto a string(src)
 * @n : integer
 *
 * Return: a pointer to a string.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	char *address = dest;

	i = 0;
	while (i < n)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	return (address);
}
/**
 * rev_str - function that reverse a string
 * @s : input string
 * Return: pointer to char
 */
char *rev_str(char *s)
{
	int i, length;
	char *dest, tmp;

	length = _strlen(s);
	dest = malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (NULL);
	_memcpy(dest, s, length);
	for (i = 0; i < length; i++, length--)
	{
		tmp = dest[length - 1];
		dest[length - 1] = dest[i];
		dest[i] = tmp;
	}
	return (dest);
}
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
