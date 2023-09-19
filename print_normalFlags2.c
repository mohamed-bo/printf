#include "main.h"

/**
 * print_address - prints address
 * @agrument: argument pointer
 * @flagPar: the parameter of format
 * Return: number char printed
 */
int print_address(va_list agrument, format_fg *flagPar)
{
	unsigned long int number = va_arg(agrument, unsigned long int);
	char *s;

	if (!number)
		return (_putString("(nil)"));
	s = convert(number, 16, UNSIGNED | LOWERCASE);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, flagPar));
}

/**
 * print_stringNonPrintable - custom format specifier
 * @agrument: argument pointer
 * @flagPar: the parameter of format
 * Return: number char printed
 */
int print_stringNonPrintable(va_list agrument, format_fg *flagPar)
{
	char *s = va_arg(agrument, char *);
	int counter = 0;
	char *hex;

	(void) flagPar;
	if (s == NULL)
		return (_putString("(null)"));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			counter += _putchar('\\');
			counter += _putchar('x');
			hex = convert(*s, 16, 0);
			counter += _putString(hex);
		}
		else
		{
			counter += _putchar(*s);
		}
	}
	return (counter);
}

/**
 * print_number - prints a number
 * @s: the number
 * @flagPar: the parameter of format
 * Return: number of char printed
 */
int print_number(char *s, format_fg *flagPar)
{
	unsigned int len = _strlen(s);
	int isNegative = (!flagPar->unsign && *s == '-');

	if (!flagPar->precision && *s == '0' && !s[1])
		s = "";
	if (isNegative)
	{
		s++;
		len--;
	}
	if (flagPar->precision != UINT_MAX)
		while (len++ < flagPar->precision)
			*--s = '0';
	if (isNegative)
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
	if (isNegative && i < flagPar->width && flagPar->zero)
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
	n += _putString(s);
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
	unsigned int counter = 0, i = _strlen(s);
	unsigned int isNegative = (!flagPar->unsign && *s == '-');

	if (!isNegative && !flagPar->unsign)
	{
	if (flagPar->plus)
		counter += _putchar('+'), i++;
	else if (flagPar->space)
		counter += _putchar(' '), i++;
	}
	counter += _putString(s);
	while (i++ < flagPar->width)
		counter += _putchar(' ');
	return (counter);
}
