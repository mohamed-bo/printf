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

	flagPar->flag |= UNSI;
	if ((flagPar->flag & HASH) && number)
		*--str = '0';
	return (counter += print_number(str, flagPar));
}

/**
 * print_oct - prints unsigned octal number
 * @agrument: the argument pointer
 * @flagPar: the parameters of format
 * Return: number of char printed
 */
int print_oct(va_list agrument, format_fg *flagPar)
{
	unsigned long int number = va_arg(agrument, unsigned long int);
	char *str;
	int counter = 0;

	flagPar->flag |= UNSI;
	number = useModifier(number, flagPar->modifier);
	str = convert(number, 8, UNSIGNED);

	if ((flagPar->flag & HASH) && number)
		*--str = '0';
	return (counter += print_number(str, flagPar));
}

/**
 * print_hex - prints unsigned hex number in lowercase
 * @agrument: the argument pointer
 * @flagPar: the parameters of format
 * Return: number of char printed
 */
int print_hex(va_list agrument, format_fg *flagPar)
{
	unsigned long int number = va_arg(agrument, unsigned long int);
	int counter = 0;
	char *str;

	flagPar->flag |= UNSI;
	number = useModifier(number, flagPar->modifier);

	str = convert(number, 16, UNSIGNED | LOWERCASE);
	if (number && (flagPar->flag & HASH))
	{
		*--str = 'x';
		*--str = '0';
	}

	return (counter += print_number(str, flagPar));
}

/**
 * print_HEX - prints unsigned hex number in UPPERCASE
 * @agrument: the argument pointer
 * @flagPar: the parameters of format
 * Return: number of char printed
 */
int print_HEX(va_list agrument, format_fg *flagPar)
{
	unsigned long int number = va_arg(agrument, unsigned long int);
	int counter = 0;
	char *str;

	flagPar->flag |= UNSI;
	number = useModifier(number, flagPar->modifier);

	str = convert(number, 16, UNSIGNED);
	if ((flagPar->flag & HASH) && number)
	{
		*--str = 'X';
		*--str = '0';
	}
	return (counter += print_number(str, flagPar));
}
