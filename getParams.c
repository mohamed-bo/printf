#include "main.h"

/**
 * get_flag_param - set the paramter of flag
 * @s: format
 * @flagPar: the parameter of s
 * @format_index: current index
 * @buffer: to optimize
 * @agruments: the argument pointer
 * Return: number of char printed
 */
int get_flag_param(const char *s, format_fg *flagPar,
va_list agruments, int *format_index, char buffer[])
{
	flagPar->flags = get_flags(s, format_index);
	flagPar->width = get_width(s, format_index, agruments);
	flagPar->precision = get_precision(s, format_index, agruments);
	flagPar->modifier = get_modifier(s, format_index);
	++(*format_index);
	return (useSpecifier(s, format_index, agruments, buffer, flagPar));
}

/**
 * get_flags - get the type of flag
 * @s: format
 * @format_index: current index
 * Return: binary array of flags:
 */
int get_flags(const char *s, int *format_index)
{
	int i, j;
	int flags = 0;
	const char flags_type[] = {'-', '+', ' ', '#', '0', '\0'};
	const int flags_int[] = {F_MINUS, F_PLUS, F_SPACE, F_HASH, F_ZERO, 0};

	for (i = *format_index + 1; s[i] != '\0'; i++)
	{
		for (j = 0; flags_type[j] != '\0'; j++)
			if (s[i] == flags_type[j])
			{
				flags |= flags_int[j];
				break;
			}

		if (flags_type[j] == 0)
			break;
	}

	*format_index = i - 1;

	return (flags);
}

/**
 * get_width - gets the width
 * @s: format
 * @format_index: current index
 * @agruments: the argument pointer
 * Return: width value
 */
int get_width(const char *s, int *format_index, va_list agruments)
{
	int i = *format_index + 1;
	int width = 0;

	if (s[i] == '*')
		width = va_arg(agruments, int), i++;
	else
		while (s[i] != '\0' && _isdigit(s[i]))
		{
			width = width * 10 + (s[i] - '0');
			i++;
		}

	*format_index = i - 1;

	return (width);
}


/**
 * get_precision -  gets the precision
 * @s: format
 * @format_index: current index
 * @agruments: the argument pointer
 * Return: Precision value
 */
int get_precision(const char *s, int *format_index, va_list agruments)
{
	int i = *format_index + 1;
	int precision = 0;

	if (s[i] != '.')
		return (-1);
	i++;
	if (s[i] == '*')
		precision = va_arg(agruments, int), i++;
	else
		while (s[i] != '\0' && _isdigit(s[i]))
		{
			precision = precision * 10 + (s[i] - '0');
			i++;
		}

	*format_index = i - 1;

	return (precision);
}

/**
 * get_modifier - get modifier if exist
 * @s: format
 * @format_index: current index
 * Return: modifier value
 */
int get_modifier(const char *s, int *format_index)
{
	int i = *format_index + 1;
	int modifier = 0;

	if (s[i] == 'l')
	{
		(*format_index)++;
		return (S_LONG);
	}
	else if (s[i] == 'h')
	{
		(*format_index)++;
		return (S_SHORT);
	}
	return (modifier);
}
