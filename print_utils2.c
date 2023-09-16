#include "main.h"

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, format_fg *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, format_fg *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero && !params->minus)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus)
		str++;
	else
		neg = 0;
	if ((params->plus && !neg2) ||
		(!params->plus && params->space && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus && params->space && !neg2 &&
		!params->unsign && params->zero)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus && params->space && !neg2 &&
		!params->unsign && !params->zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, format_fg *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero && !params->minus)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus)
		str++;
	else
		neg = 0;

	if (params->plus && !neg2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space && !neg2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}