#include "main.h"

/**
 * print_char - prints char
 * @agruments: argument pointer
 * @buffer: to optimize printf
 * @flagPar: the parameter of format
 * Return: number char printed
 */

int print_char(va_list agruments, char buffer[], format_fg *flagPar)
{
	char c = va_arg(agruments, int);

	return (_putCharr(c, buffer, flagPar));
}

/**
 * print_int - prints integer
 * @agruments: argument pointer
 * @buffer: to optimize printf
 * @flagPar: the parameter of format
 * Return: number char printed
 */

int print_int(va_list agruments, char buffer[], format_fg *flagPar)
{
	long int n = va_arg(agruments, long int);
	int i = BUFF_SIZE - 2;
	int isNegative = 0;
	int len;
	char padChar = ' ', beforChar = 0;
	unsigned long int number;

	n = modifierFun(n, flagPar->modifier);
	if ((flagPar->flags & F_ZERO) && !(flagPar->flags & F_MINUS))
		padChar = '0';
	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int) n;

	if (n < 0)
	{
		isNegative = 1;
		number = (unsigned long int)((-1) * n);
	}

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;
	len = BUFF_SIZE - i - 1;
	if (isNegative)
		beforChar = '-';
	else if (flagPar->flags & F_PLUS)
		beforChar = '+';
	else if (flagPar->flags & F_SPACE)
		beforChar = ' ';

	return (_putNumber(i, buffer, flagPar, len, padChar, beforChar));
}

/**
 * print_string - prints string
 * @agruments: argument pointer
 * @buffer: to optimize printf
 * @flagPar: the parameter of format
 * Return: number char printed
 */

int print_string(va_list agruments, char buffer[], format_fg *flagPar)
{
	char *s = va_arg(agruments, char *);
	int i, len = 0;

	UNUSED(buffer);
	if (s == NULL)
	{
		s = "(null)";
		if (flagPar->precision >= 6)
			s = " ";
	}

	len = _strlen(s);

	if (flagPar->precision >= 0 && flagPar->precision < len)
		len = flagPar->precision;

	if (flagPar->width > len)
	{
		if (flagPar->flags & F_MINUS)
		{
			write(1, &s[0], len);
			for (i = flagPar->width - len; i > 0; i--)
				write(1, " ", 1);
			return (flagPar->width);
		}
		else
		{
			for (i = flagPar->width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &s[0], len);
			return (flagPar->width);
		}
	}

	return (write(1, s, len));
}

/**
 * print_percent - prints string
 * @agruments: argument pointer
 * @buffer: to optimize printf
 * @flagPar: the parameter of format
 * Return: number char printed
 */

int print_percent(va_list agruments, char buffer[], format_fg *flagPar)
{
	UNUSED(agruments);
	UNUSED(buffer);
	UNUSED(flagPar);

	return (write(1, "%%", 1));
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @agruments: argument pointer
 * @buffer: to optimize printf
 * @flagPar: the parameter of format
 * Return: number char printed
 */

int print_unsigned(va_list agruments, char buffer[], format_fg *flagPar)
{
	unsigned long int number = va_arg(agruments, unsigned long int);
	int i = BUFF_SIZE - 2;

	number = useMoidifier(number, flagPar->modifier);
	buffer[BUFF_SIZE - 1] = '\0';
	if (number == 0)
		buffer[i--] = '0';
	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;
	return (handleUnsined(i, buffer, flagPar));
}
