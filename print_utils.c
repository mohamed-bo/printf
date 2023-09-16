#include "main.h"

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
 *_strlen -  function that returns the length of a string.
 * @s: string value
 *Return: returns the length of a string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * printRange - prints a range of char from begin to end
 * @begin: starting address
 * @end: ending address
 * @except: except address
 * Return: number of char printed
 */
int printRange(char *begin, char *end, char *except)
{
	int counter = 0;

	while (begin <= end)
	{
		if (begin != except)
			counter += _putchar(*begin);
		begin++;
	}
	return (counter);
}

/**
 * print_rev - prints string in reverse
 * @agrument: string
 * @flagPar: the parameter of format
 * Return: number of char printed
 */
int print_rev(va_list agrument, format_fg *flagPar)
{
	int i, counter = 0;
	char *s = va_arg(agrument, char *);

    (void)flagPar;
	if (s)
	{
		for (i = 0; *s; s++)
			i++;
		s--;
		for (; i > 0; i--, s--)
			counter += _putchar(*s);
	}
	return (counter);
}

/**
 * print_rot13 - prints string in rot13
 * @agrument: string
 * @flagPar: the parameter of format
 * Return: number of char printed
 */
int print_rot13(va_list agrument, format_fg *flagPar)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(agrument, char *);
	(void)flagPar;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}

/**
 * print_number - prints a number
 * @s: the number
 * @flagPar: the parameter of format
 * Return: number of char printed
 */
int print_number(char *s, format_fg *flagPar)
{
	unsigned int i = _strlen(s);
	int signn = (!flagPar->unsign && *s == '-');

	if (!flagPar->precision && *s == '0' && !s[1])
		s = "";
	if (signn)
	{
		s++;
		i--;
	}
	if (flagPar->precision != UINT_MAX)
		while (i++ < flagPar->precision)
			*--s = '0';
	if (signn)
		*--s = '-';

	if (!flagPar->minus)
		return (print_number_right_shift(s, flagPar));
	else
		return (print_number_left_shift(s, flagPar));
}

/**
 * print_number_right_shift - prints a number flag non minus
 * @s: the number
 * @flagPar: the parameter of format
 * Return: number of char printed
 */
int print_number_right_shift(char *s, format_fg *flagPar)
{
	unsigned int n = 0, isNegative, i = _strlen(s);
	char paddingChar = flagPar->zero ? '0' : ' ';
    unsigned int signn;

	signn = isNegative = (!flagPar->unsign && *s == '-');
	if (signn && i < flagPar->width && flagPar->zero)
		s++;
	else
		signn = 0;
	if ((flagPar->plus && !isNegative) ||
		(!flagPar->plus && flagPar->space && !isNegative))
		i++;
	if (signn && flagPar->zero)
		n += _putchar('-');
	if (flagPar->plus && !isNegative && flagPar->zero && !flagPar->unsign)
		n += _putchar('+');
	else if (!flagPar->plus && flagPar->space && !isNegative &&
		!flagPar->unsign && flagPar->zero)
		n += _putchar(' ');
	while (i++ < flagPar->width)
		n += _putchar(paddingChar);
	if (signn && !flagPar->zero)
		n += _putchar('-');
	if (flagPar->plus && !isNegative && !flagPar->zero && !flagPar->unsign)
		n += _putchar('+');
	else if (!flagPar->plus && flagPar->space && !isNegative &&
		!flagPar->unsign && !flagPar->zero)
		n += _putchar(' ');
	n += _puts(s);
	return (n);
}

/**
 * print_number_left_shift - prints a number flag minus
 * @s: the number
 * @flagPar: the parameter of format
 * Return: number of char printed
 */
int print_number_left_shift(char *s, format_fg *flagPar)
{
	unsigned int n = 0, isNegative, i = _strlen(s);

	isNegative = (!flagPar->unsign && *s == '-');
	if (flagPar->plus && !isNegative && !flagPar->unsign)
		n += _putchar('+'), i++;
	else if (flagPar->space && !isNegative && !flagPar->unsign)
		n += _putchar(' '), i++;
	n += _puts(s);
	while (i++ < flagPar->width)
		n += _putchar(' ');
	return (n);
}
