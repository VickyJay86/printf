#include "main.h"

/**
 * print_bigS - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of  printed char
 */
int print_bigS(va_list l, flags_t *f)
{
	int y, tally = 0;
	char *res;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (_puts("(null)"));

	for (y = 0; s[y]; y++)
	{
		if (s[y] > 0 && (s[y] < 32 || s[y] >= 127))
		{
			_puts("\\x");
			tally += 2;
			res = convert(s[y], 16, 0);
			if (!res[1])
				tally += _putchar('0');
			tally += _puts(res);
		}
		else
			tally += _putchar(s[y]);
	}
	return (tally);
}

/**
 * print_rev - prints a string in reverse
 * @l: argument from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rev(va_list l, flags_t *f)
{
	int x = 0, y;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";

	while (s[x])
		x++;

	for (y = x - 1; y >= 0; y--)
		_putchar(s[y]);

	return (x);
}

/**
 * print_rot13 - prints a string using rot13
 * @l: list of arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rot13(va_list l, flags_t *f)
{
	int x, y;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(l, char *);

	(void)f;
	for (y = 0; s[y]; y++)
	{
		if (s[y] < 'A' || (s[y] > 'Z' && s[y] < 'a') || s[y] > 'z')
			_putchar(s[y]);
		else
		{
			for (x = 0; x <= 52; x++)
			{
				if (s[y] == rot13[x])
					_putchar(ROT13[x]);
			}
		}
	}

	return (y);
}

/**
 * print_percent - prints a percent
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */
int print_percent(va_list l, flags_t *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}
