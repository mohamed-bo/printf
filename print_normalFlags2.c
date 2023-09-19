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
	int i = 0, offset = 0;
	char *str = va_arg(agrument, char *);
	char buffer[1024];

	(void) flagPar;
	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] < 127)
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
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

	if (!flagPar->minus)
		return (print_number_right_shift(s, flagPar));
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

