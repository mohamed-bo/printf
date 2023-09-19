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
			if (!hex[1])
				counter += _putchar('0');
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
	int isNegative = (!(flagPar->flag & UNSI) && *s == '-');
	unsigned int counter = 0, i = _strlen(s);

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

	if (!(flagPar->flag & MINUS))
		return (printNonMinus(s, flagPar));
	if (!isNegative && !(flagPar->flag & UNSI))
	{
	if ((flagPar->flag & PLUS))
		counter += _putchar('+'), i++;
	else if ((flagPar->flag & SPACE))
		counter += _putchar(' '), i++;
	}
	counter += _putString(s);
	while (i++ < flagPar->width)
		counter += _putchar(' ');
	return (counter);
}

/**
 * printNonMinus - prints a number flag non minus
 * @s: the number
 * @flagPar: the parameter of format
 * Return: number of char printed
 */
int printNonMinus(char *s, format_fg *flagPar)
{
	unsigned int counter = 0, isNegative, i = _strlen(s);
	char paddingChar = (flagPar->flag & ZERO) ? '0' : ' ';
	unsigned int signn;

	signn = isNegative = (!(flagPar->flag & UNSI) && *s == '-');
	if (isNegative && i < flagPar->width && (flagPar->flag & ZERO))
		s++;
	else
		signn = 0;
	if (((flagPar->flag & PLUS) && !isNegative) ||
		(!(flagPar->flag & PLUS) && (flagPar->flag & SPACE) && !isNegative))
		i++;
	if (signn && (flagPar->flag & ZERO))
		counter += _putchar('-');
	if ((flagPar->flag & PLUS) && !isNegative && (flagPar->flag & ZERO) && !(flagPar->flag & UNSI))
		counter += _putchar('+');
	else if (!(flagPar->flag & PLUS) && (flagPar->flag & SPACE) && !isNegative &&
		!(flagPar->flag & UNSI) && (flagPar->flag & ZERO))
		counter += _putchar(' ');
	while (i++ < flagPar->width)
		counter += _putchar(paddingChar);
	if (signn && !(flagPar->flag & ZERO))
		counter += _putchar('-');
	if ((flagPar->flag & PLUS) && !isNegative && !(flagPar->flag & ZERO) && !(flagPar->flag & UNSI))
		counter += _putchar('+');
	else if (!(flagPar->flag & PLUS) && (flagPar->flag & SPACE) && !isNegative &&
		!(flagPar->flag & UNSI) && !(flagPar->flag & ZERO))
		counter += _putchar(' ');
	counter += _putString(s);
	return (counter);
}

