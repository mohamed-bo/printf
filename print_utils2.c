#include "main.h"

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
