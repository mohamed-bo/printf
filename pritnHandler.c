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
	return (handle_adresse(s, flagPar));
}

/**
 * handle_adresse - prints a number
 * @s: the number
 * @flagPar: the parameter of format
 * Return: number of char printed
 */
int handle_adresse(char *s, format_fg *flagPar)
{
	unsigned int counter = 0, len = _strlen(s);
	char extra_c = 0, padd = ' ';
	static char buffer[1024];
	char *padding = &buffer[1023];
	unsigned int i;

    *padding= '\0';
	if ((flagPar->zero) && !(flagPar->minus))
		padd = '0';
	if (flagPar->plus)
		extra_c = '+', len++;
	else if (flagPar->space)
		extra_c = ' ', len++;

	if (flagPar->width > len)
	{
		for (i = 1; i < flagPar->width - len; i++)
		{
			*--padding = padd;
		}
		if (flagPar->minus && padd == ' ')/* Asign extra char to left of buffer */
		{
			*--s = 'x';
			*--s = '0';
			if (extra_c)
				*--s = extra_c;
			counter += _putString(s);
			counter += _putString(padding);
			return (counter);
		}
		else if (!(flagPar->minus) && padd == ' ')/* extra char to left of buffer */
		{
			*--s = 'x';
			*--s = '0';
			if (extra_c)
				*--s = extra_c;
			counter += _putString(padding);
			counter += _putString(s);
			return (counter);
		}
		else if (!(flagPar->minus) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				*--padding = extra_c;
			*--padding = '0';
			*--padding = 'x';
			counter += _putString(padding);
			counter += _putString(s);
			return (counter);
		}
	}
	*--s = 'x';
	*--s = '0';
	if (extra_c)
		*--s = extra_c;
	counter += _putString(s);
	return (counter);
}

/**
 * write_num - prints a number
 * @s: the number
 * @flagPar: the parameter of format
 * Return: number of char printed
 */
int write_num(char *s, format_fg *flagPar)
{
	unsigned length = _strlen (s);
	char padd = ' ', extra_ch;
	static char buffer[1024];
	char *padding = &buffer[1023];
	unsigned int i, counter = 0;

    *padding = '\0';
	if ((flagPar->zero) && !(flagPar->minus))
		padd = '0';
	if ((*s) == '-')
		extra_ch = '-', s++, length--;
	else if (flagPar->plus)
		extra_ch = '+';
	else if (flagPar->space)
		extra_ch = ' ';
	if (flagPar->precision == 0 && *s == '0' && flagPar->width == 0)
		return (0);
	if (flagPar->precision == 0 && *s == '0')
		*--s = ' ';
	if (flagPar->precision > 0 && flagPar->precision < length)
		padd = ' ';
	while (flagPar->precision > length)
		*--s = '0', length++;
	if (flagPar->width > length)
	{
		for (i = 0; i < flagPar->width - length; i++)
			*--padding = padd;
		if (flagPar->minus && padd == ' ')
		{
			if (extra_ch)
				*--s = extra_ch;
			counter += _putString(s);
			counter += _putString(padding);
			return (counter);
		}
		else if (!(flagPar->minus) && padd == ' ')
		{
			if (extra_ch)
				*--s = extra_ch;
			counter += _putString(padding);
			counter += _putString(s);
			return (counter);
		}
		else if (!(flagPar->minus) && padd == '0')
		{
			if (extra_ch)
				*--padding = extra_ch;
			counter += _putString(padding);
			counter += _putString(s);
			return (counter);
		}
	}
	if (extra_ch)
		*--s = extra_ch;
	counter += _putString(s);
	return (counter);
}
/**
 * write_unsgnd - prints a number
 * @s: the number
 * @flagPar: the parameter of format
 * Return: number of char printed
 */

int write_unsgnd(char *s, format_fg *flagPar)
{
	unsigned int length = _strlen (s);
	char padd = ' ';
	static char buffer[1024];
	char *padding = &buffer[1023];
	unsigned int i, counter = 0;

	*padding = '\0';
	if (flagPar->precision == 0 && *s == '0')
		return (0);

	if (flagPar->precision > 0 && flagPar->precision < length)
		padd = ' ';

	while (flagPar->precision > length)
	{
		*--s = '0';
		length++;
	}

	if ((flagPar->zero) && !(flagPar->minus))
		padd = '0';

	if (flagPar->width > length)
	{
		for (i = 0; i < flagPar->width - length; i++)
			*--padding = padd;

		if (flagPar->minus)
		{
			counter += _putString(s);
			counter += _putString(padding);
			return (counter);
		}
		else
		{
			counter += _putString(padding);
			counter += _putString(s);
			return (counter);
		}
	}

	counter += _putString(s);
	return (counter);
}
