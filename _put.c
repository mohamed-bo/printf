#include "main.h"

/**
 * _putString - prints a string
 * @s: the string to print
 * Return: number of char printed
 */
int _putString(char *s)
{
	char *begin = s;

	while (*s)
		_putchar(*s++);
	return (s - begin);
}

/**
 * _putchar - using write function to print
 * the character c to stdout.
 * @c: char
 * Return: 1 if success.
 */
int _putchar(int c)
{
	static int i;
	static char buffer[OUTPUT_BUF_SIZE];

	if (c == EXITT || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != EXITT)
		buffer[i++] = c;
	return (1);
}
