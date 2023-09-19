#include "main.h"

/**
 * _putCharr - handle %c %s
 * @c: character to print
 * @buffer: to optimize printf
 * @flagPar: the parameter of format
 * Return: counter
 */
int _putCharr(char c, char buffer[], format_fg *flagPar)
{
	int i = 0;
	char paddinChar = ' ';
	int count;

	if (flagPar->flags & F_ZERO)
		paddinChar = '0';
	buffer[i] = c;
	buffer[++i] = '\0';
	if (flagPar->width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < flagPar->width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = paddinChar;

		if (flagPar->flags & F_MINUS)
		{
			count = write(1, &buffer[0], 1)
			 + write(1, &buffer[BUFF_SIZE - i - 1], flagPar->width - 1);
			return (count);
		}
		else
		{
			count = write(1, &buffer[BUFF_SIZE - i - 1], flagPar->width - 1)
			 + write(1, &buffer[0], 1);
			return (count);
		}
	}
	return (write(1, &buffer[0], 1));
}

/**
 * handlePointer - handle adress
 * @buffer: to optimize
 * @current: current adress
 * @lenn: size or length of number
 * @paddinChar: padding character
 * @beforChar: first charactyer
 * @flagPar: the parameter of format
 * Return: counter
 */
int handlePointer(char buffer[], int current, int lenn, char paddinChar,
	char beforChar, format_fg *flagPar)
{
	int i;
	int padd_start = 1;

	if (flagPar->width > lenn)
	{
		for (i = 3; i < flagPar->width - lenn + 3; i++)
			buffer[i] = paddinChar;
		buffer[i] = '\0';
		if (flagPar->flags & F_MINUS && paddinChar == ' ')
		{
			buffer[--current] = 'x';
			buffer[--current] = '0';
			if (beforChar)
				buffer[--current] = beforChar;
			return (write(1, &buffer[current], lenn) + write(1, &buffer[3], i - 3));
		}
		else if (!(flagPar->flags & F_MINUS) && paddinChar == ' ')
		{
			buffer[--current] = 'x';
			buffer[--current] = '0';
			if (beforChar)
				buffer[--current] = beforChar;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[current], lenn));
		}
		else if (!(flagPar->flags & F_MINUS) && paddinChar == '0')
		{
			if (beforChar)
				buffer[--padd_start] = beforChar;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[current], lenn - (1 - padd_start) - 2));
		}
	}
	buffer[--current] = 'x';
	buffer[--current] = '0';
	if (beforChar)
		buffer[--current] = beforChar;
	return (write(1, &buffer[current], BUFF_SIZE - current - 1));
}

/**
 * print_address - prints address
 * @agruments: argument pointer
 * @buffer: to optimize printf
 * @flagPar: the parameter of format
 * Return: number char printed
 */

int print_address(va_list agruments, char buffer[], format_fg *flagPar)
{
	void *adress = va_arg(agruments, void *);
	char beforChar = 0, paddinChar = ' ';
	int len = BUFF_SIZE - 2;
	int currentLen = 2;
	unsigned long adressNumber;
	char array[] = "0123456789abcdef";

	if (adress == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';

	adressNumber = (unsigned long)adress;
	while (adressNumber > 0)
	{
		buffer[len--] = array[adressNumber % 16];
		adressNumber /= 16;
		currentLen++;
	}
	if (flagPar->flags & F_PLUS)
		beforChar = '+', currentLen++;
	else if (flagPar->flags & F_SPACE)
		beforChar = ' ', currentLen++;
	if ((flagPar->flags & F_ZERO) && !(flagPar->flags & F_MINUS))
		paddinChar = '0';
	len++;

	return (handlePointer(buffer, len, currentLen, paddinChar,
	 beforChar, flagPar));
}

/**
 * print_stringNonPrintable - custom format specifier
 * @agruments: argument pointer
 * @buffer: to optimize printf
 * @flagPar: the parameter of format
 * Return: number char printed
 */

int print_stringNonPrintable(va_list agruments, char buffer[],
	format_fg *flagPar)
{
	char *s = va_arg(agruments, char *);
	int len = 0, after = 0;

	UNUSED(flagPar);
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[len] != '\0')
	{
		if (s[len] >= 32 && s[len] < 127)
			buffer[len + after] = s[len];
		else
			after += addHex(s[len], buffer, len + after);
		len++;
	}
	buffer[len + after] = '\0';
	return (write(1, buffer, len + after));
}

/**
 * print_rot13 - custom format specifier
 * @agruments: argument pointer
 * @buffer: to optimize printf
 * @flagPar: the parameter of format
 * Return: number char printed
 */
int print_rot13(va_list agruments, char buffer[], format_fg *flagPar)
{
	char *s = va_arg(agruments, char *);
	int i;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";

	UNUSED(buffer);
	UNUSED(flagPar);

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
			write(1, &arr[s[i] - 65], 1);
		else
			write(1, &s[i], 1);
		count++;
	}
	return (count);
}
