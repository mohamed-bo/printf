#include "main.h"

/**
 * init_params - clear the paramter and reset buffer
 * @flagPar: the parameter of format
 * @agruments: the argument pointer
 */
void init_params(format_fg *flagPar, va_list agruments)
{
	flagPar->flag = 0;

	flagPar->width = 0;
	flagPar->precision = UINT_MAX;

	flagPar->modifier = 0;
	flagPar->specifier = NULL;
	(void)agruments;
}

/**
 * get_flag_param - set the paramter of flag
 * @s: the format string
 * @flagPar: the parameter of format
 * @agruments: the argument pointer
 * Return: current s pointer
 */
char *get_flag_param(char *s, format_fg *flagPar, va_list agruments)
{
	while (get_flag(s, flagPar))
	{
		s++;
	}
	s = get_width(s, flagPar, agruments);
	s = get_precision(s, flagPar, agruments);
	s = get_modifier(s, flagPar);
	get_specifier(s, flagPar);
	return (s);
}


/**
 * get_flag - get the type of flag
 * @s: the format string
 * @flagPar: the parameter of format
 * Return: if flag was valid
 */
int get_flag(char *s, format_fg *flagPar)
{

	switch (*s)
	{
		case '+':
			flagPar->flag |= PLUS;
			return (1);
		case ' ':
			flagPar->flag |= SPACE;
			return (1);
		case '#':
			flagPar->flag |= HASH;
			return (1);
		case '-':
			flagPar->flag |= MINUS;
			return (1);
		case '0':
			flagPar->flag |= ZERO;
			return (1);
	}
	return (0);
}

/**
 * get_width - gets the width
 * @s: the format string
 * @flagPar: the parameter of format
 * @agrument: the argument pointer
 * Return: current s pointer
 */
char *get_width(char *s, format_fg *flagPar, va_list agrument)
{
	int width = 0;

	if (*s == '*')
	{
		width = va_arg(agrument, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			width = width * 10 + (*s++ - '0');
	}
	flagPar->width = width;
	return (s);
}

/**
 * get_precision - gets the precision
 * @s: the format string
 * @flagPar: the parameter of format
 * @agrument: the argument pointer
 * Return: current s pointer
 */
char *get_precision(char *s, format_fg *flagPar, va_list agrument)
{
	int precision = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		precision = va_arg(agrument, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			precision = precision * 10 + (*s++ - '0');
	}
	flagPar->precision = precision;
	return (s);
}
