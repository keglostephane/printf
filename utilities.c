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
 * rev_str - function that reverse a string in place
 * @s : input string
 * Return: pointer to char
 */
char *rev_str(char *s)
{
	int i, j, length;
	char tmp;

	i = 0;
	length = _strlen(s);
	j = length - 1;

	while (i <= length / 2)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;

		i++;
		j--;
	}
	return (s);
}
