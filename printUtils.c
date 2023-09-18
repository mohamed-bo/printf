#include "main.h"

/**
 * modifierFun - cast variable
 * @number: ling
 * @modifier: type to cast to
 * Return: casted variable
 */
long int modifierFun(long int number, int modifier)
{
	if (modifier == S_LONG)
		return (number);
	else if (modifier == S_SHORT)
		return ((short)number);

	return ((int)number);
}

/**
 * useMoidifier - modifier function
 * @number: ling
 * @modifier: type to cast to
 * Return: casted variable
 */
long int useMoidifier(unsigned long int number, int modifier)
{
	if (modifier == S_LONG)
		return (number);
	else if (modifier == S_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}

/**
 * addHex - add hex Code
 * @buffer: to optimize
 * @i: current index
 * @c: character
 * Return: 3 len of printed char
 */
int addHex(char c, char buffer[], int i)
{
	char array[] = "0123456789ABCDEF";

	if (c < 0)
		c *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = array[c / 16];
	buffer[i] = array[c % 16];

	return (3);
}

/**
 * _isdigit - checks in input is digit
 * @c: character to be checked
 * Return: 1 if true, 0 if false
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * print_rev - prints string in reverse
 * @agruments: string
 * @buffer: to optimize printf
 * @flagPar: the parameter of format
 * Return: number of char printed
 */
int print_rev(va_list agruments, char buffer[], format_fg *flagPar)
{
	int i, counter = 0;
	char *s = va_arg(agruments, char *);

	UNUSED(flagPar);
	UNUSED(buffer);
	if (s)
	{
		for (i = 0; *s; s++)
			i++;
		s--;
		for (; i > 0; i--, s--)
		{
			write(1, s, 1);
			counter++;
		}
	}
	return (counter);
}
