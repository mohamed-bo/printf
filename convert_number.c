#include "main.h"

/**
 * print_bin - prints unsigned binary number
 * @agrument: the argument pointer
 * @flagPar: the parameters of format
 * Return: number of char printed
 */
int print_bin(va_list agrument, format_fg *flagPar)
{
	unsigned int number = va_arg(agrument, unsigned int);
	char *str = convert(number, 2, UNSIGNED);
	int counter = 0;

	flagPar->unsign = 1;
	if (flagPar->hashtag && number)
		*--str = '0';
	return (counter += write_unsgnd(str, flagPar));
}

/**
 * print_oct - prints unsigned octal number
 * @agrument: the argument pointer
 * @flagPar: the parameters of format
 * Return: number of char printed
 */
int print_oct(va_list agrument, format_fg *flagPar)
{
	unsigned long number;
	char *str;
	int counter = 0;

	flagPar->unsign = 1;
	if (flagPar->l_mod)
		number = (unsigned long)va_arg(agrument, unsigned long);
	else if (flagPar->h_mod)
		number = (unsigned short int)va_arg(agrument, unsigned int);
	else
		number = (unsigned int)va_arg(agrument, unsigned int);
	str = convert(number, 8, UNSIGNED);

	if (flagPar->hashtag && number)
		*--str = '0';
	return (counter += write_unsgnd(str, flagPar));
}

/**
 * print_hex - prints unsigned hex number in lowercase
 * @agrument: the argument pointer
 * @flagPar: the parameters of format
 * Return: number of char printed
 */
int print_hex(va_list agrument, format_fg *flagPar)
{
	unsigned long number;
	int counter = 0;
	char *str;

	flagPar->unsign = 1;
	if (flagPar->l_mod)
		number = (unsigned long)va_arg(agrument, unsigned long);
	else if (flagPar->h_mod)
		number = (unsigned short int)va_arg(agrument, unsigned int);
	else
		number = (unsigned int)va_arg(agrument, unsigned int);

	str = convert(number, 16, UNSIGNED | LOWERCASE);
	if (number && flagPar->hashtag)
	{
		*--str = 'x';
		*--str = '0';
	}

	return (counter += write_unsgnd(str, flagPar));
}

/**
 * print_HEX - prints unsigned hex number in UPPERCASE
 * @agrument: the argument pointer
 * @flagPar: the parameters of format
 * Return: number of char printed
 */
int print_HEX(va_list agrument, format_fg *flagPar)
{
	unsigned long number;
	int counter = 0;
	char *str;

	flagPar->unsign = 1;
	if (flagPar->l_mod)
		number = (unsigned long)va_arg(agrument, unsigned long);
	else if (flagPar->h_mod)
		number = (unsigned short int)va_arg(agrument, unsigned int);
	else
		number = (unsigned int)va_arg(agrument, unsigned int);

	str = convert(number, 16, UNSIGNED);
	if (flagPar->hashtag && number)
	{
		*--str = 'X';
		*--str = '0';
	}
	return (counter += write_unsgnd(str, flagPar));
}
