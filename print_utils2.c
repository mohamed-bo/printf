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
	unsigned int n = 0, neg, neg2, i = _strlen(s);
	char pad_char = ' ';

	if (flagPar->zero && !flagPar->minus)
		pad_char = '0';
	neg = neg2 = (!flagPar->unsign && *s == '-');
	if (neg && i < flagPar->width && pad_char == '0' && !flagPar->minus)
		s++;
	else
		neg = 0;
	if ((flagPar->plus && !neg2) ||
		(!flagPar->plus && flagPar->space && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (flagPar->plus && !neg2 && pad_char == '0' && !flagPar->unsign)
		n += _putchar('+');
	else if (!flagPar->plus && flagPar->space && !neg2 &&
		!flagPar->unsign && flagPar->zero)
		n += _putchar(' ');
	while (i++ < flagPar->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (flagPar->plus && !neg2 && pad_char == ' ' && !flagPar->unsign)
		n += _putchar('+');
	else if (!flagPar->plus && flagPar->space && !neg2 &&
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
	unsigned int n = 0, neg, neg2, i = _strlen(s);
	char pad_char = ' ';

	if (flagPar->zero && !flagPar->minus)
		pad_char = '0';
	neg = neg2 = (!flagPar->unsign && *s == '-');
	if (neg && i < flagPar->width && pad_char == '0' && !flagPar->minus)
		s++;
	else
		neg = 0;

	if (flagPar->plus && !neg2 && !flagPar->unsign)
		n += _putchar('+'), i++;
	else if (flagPar->space && !neg2 && !flagPar->unsign)
		n += _putchar(' '), i++;
	n += _puts(s);
	while (i++ < flagPar->width)
		n += _putchar(pad_char);
	return (n);
}
