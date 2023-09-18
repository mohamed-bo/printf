#include "main.h"

/**
 * print_bin - prints unsigned binary number
 * @agruments: the argument pointer
 * @buffer: to optimize printf
 * @flagPar: the parameters of format
 * Return: number of char printed
 */

int print_bin(va_list agruments, char buffer[], format_fg *flagPar)
{
	unsigned int n;
	int count;
	char *binary;

	UNUSED(buffer);
	UNUSED(flagPar);
	n = va_arg(agruments, unsigned int);

	binary = convert(n, 2, LOWERCASE);

	for (; *binary != '\0'; binary++)
	{
		write(1, binary, 1);
		count++;
	}
	return (count);
}


/**
 * print_oct - prints unsigned octal number
 * @agruments: the argument pointer
 * @buffer: to optimize printf
 * @flagPar: the parameters of format
 * Return: number of char printed
 */

int print_oct(va_list agruments, char buffer[], format_fg *flagPar)
{
	unsigned long int number = va_arg(agruments, unsigned long int);
	signed int i = BUFF_SIZE - 2;
	signed int isHashNonZ = flagPar->flags & F_HASH && number != 0;

	buffer[BUFF_SIZE - 1] = '\0';
	number = useMoidifier(number, flagPar->modifier);
	if (number == 0)
		buffer[i--] = '0';
	while (number > 0)
	{
		buffer[i--] = (number % 8) + '0';
		number /= 8;
	}
	if (isHashNonZ)
		buffer[i--] = '0';
	i++;
	return (handleUnsined(i, buffer, flagPar));
}

/**
 * print_hex - prints unsigned hex number in lowercase
 * @agruments: the argument pointer
 * @buffer: to optimize printf
 * @flagPar: the parameters of format
 * Return: number of char printed
 */

int print_hex(va_list agruments, char buffer[], format_fg *flagPar)
{
	return (printHexaDecimal(agruments, LOWERCASE, flagPar, buffer, 'x'));
}

/**
 * print_HEXUP - prints unsigned hex number in lowercase
 * @agruments: the argument pointer
 * @buffer: to optimize printf
 * @flagPar: the parameters of format
 * Return: number of char printed
 */

int print_HEXUP(va_list agruments, char buffer[], format_fg *flagPar)
{
	return (printHexaDecimal(agruments, 0, flagPar, buffer, 'X'));
}

/**
 * print_hex - prints unsigned hex number in lowercase
 * @agruments: the argument pointer
 * @flag: is lower or upper
 * @flagPar: the parameters of format
 * @buffer: to optimize printf
 * @beforChar: character before convert
 * Return: number of char printed
 */

int printHexaDecimal(va_list agruments, int flag, format_fg *flagPar,
	char buffer[], char beforChar)
{
	unsigned long int number = va_arg(agruments, unsigned long int);
	char *array = flag & LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	int i = BUFF_SIZE - 2;
	int isHashNonZ = flagPar->flags & F_HASH && number != 0;

	UNUSED(flagPar->width);

	number = useMoidifier(number, flagPar->modifier);
	buffer[BUFF_SIZE - 1] = '\0';
	if (number == 0)
		buffer[i--] = '0';

	while (number > 0)
	{
		buffer[i--] = array[number % 16];
		number /= 16;
	}

	if (isHashNonZ)
	{
		buffer[i--] = beforChar;
		buffer[i--] = '0';
	}
	i++;
	return (handleUnsined(i, buffer, flagPar));
}
