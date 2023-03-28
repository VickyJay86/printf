#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * _putchar uses a local buffer of 1024 to call write
 * @c: Input char
 * Return: On success 1.
 * On error, -1 is returned
 */
int _putchar(char c)
{
	static char buf[1024];
	static int x;

	if (c == -1 || x >= 1024)
	{
		write(1, &buf, x);
		x = 0;
	}
	if (c != -1)
	{
		buf[x] = c;
		x++;
	}
	return (1);
}

/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 * Return: number of written chars
 */
int _puts(char *str)
{
	register int x;

	for (x = 0; str[x] != '\0'; x++)
		_putchar(str[x]);
	return (x);
}
