#include "main.h"

/**
 * print_char - prints char
 * @agrument: argument pointer
 * @flagPar: the parameter of format
 * Return: number char printed
 */
int print_char(va_list agrument, format_fg *flagPar)
{
	unsigned int ch = va_arg(agrument, int);
	unsigned int width = 1, counter = 0;

	if (flagPar->minus)
		counter += _putchar(ch);
	while (width++ < flagPar->width)
		counter += _putchar(' ');
	if (!flagPar->minus)
		counter += _putchar(ch);
	return (counter);
}

/**
 * print_int - prints integer
 * @agrument: argument pointer
 * @flagPar: the parameter of format
 * Return: number char printed
 */
int print_int(va_list agrument, format_fg *flagPar)
{
	long number;

	if (flagPar->l_mod)
		number = va_arg(agrument, long);
	else if (flagPar->h_mod)
		number = (short int)va_arg(agrument, int);
	else
		number = (int)va_arg(agrument, int);
	return (print_number(convert(number, 10, 0), flagPar));
}

/**
 * print_string - prints string
 * @agrument: argument pointer
 * @flagPar: the parameter of format
 * Return: number char printed
 */
int print_string(va_list agrument, format_fg *flagPar)
{
	char *s = va_arg(agrument, char *);
	unsigned int precision, counter = 0, i = 0, j;

	(void)flagPar;
	if ((int)(!s))
			s = "(null)";

	j = precision = _strlen(s);
	if (flagPar->precision < precision)
		j = precision = flagPar->precision;

	if (flagPar->minus)
	{
		for (i = 0; i < precision; i++)
			counter += _putchar(*s++);
	}
	while (j++ < flagPar->width)
		counter += _putchar(' ');
	if (!flagPar->minus)
	{
		for (i = 0; i < precision; i++)
			counter += _putchar(*s++);
	}
	return (counter);
}

/**
 * print_percent - prints string
 * @agrument: argument pointer
 * @flagPar: the parameter of format
 * Return: number char printed
 */
int print_percent(va_list agrument, format_fg *flagPar)
{
	(void)agrument;
	(void)flagPar;
	return (_putchar('%'));
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @agrument: argument pointer
 * @flagPar: the parameter of format
 * Return: number char printed
 */
int print_unsigned(va_list agrument, format_fg *flagPar)
{
	unsigned long number;

	flagPar->unsign = 1;
	if (flagPar->l_mod)
		number = (unsigned long)va_arg(agrument, unsigned long);
	else if (flagPar->h_mod)
		number = (unsigned short int)va_arg(agrument, unsigned int);
	else
		number = (unsigned int)va_arg(agrument, unsigned int);
	return (print_number(convert(number, 10, UNSIGNED), flagPar));
}
