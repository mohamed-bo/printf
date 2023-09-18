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
	return (write_num(convert(number, 10, 0), flagPar));
}

/**
 * print_string - prints string
 * @agrument: argument pointer
 * @flagPar: the parameter of format
 * Return: number char printed
 */
int print_string(va_list agrument, format_fg *flagPar)
{
	char *str = va_arg(agrument, char *);
	unsigned int length = 0, i;

	(void)flagPar;

	if (str == NULL)
	{
		str = "(null)";
		if (flagPar->precision >= 6)
			str = " ";
	}

	while (str[length] != '\0')
		length++;

	if (flagPar->precision > 0 && flagPar->precision < length)
		length = flagPar->precision;

	if (flagPar->width > length)
	{
		if (flagPar->minus)
		{
			write(1, &str[0], length);
			for (i = flagPar->width - length; i > 0; i--)
				write(1, " ", 1);
			return (flagPar->width);
		}
		else
		{
			for (i = flagPar->width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (flagPar->width);
		}
	}

	return (write(1, str, length));
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
	return (write_unsgnd(convert(number, 10, UNSIGNED), flagPar));
}
