#include "main.h"

/**
 * get_modifier - get the modifier type
 * @s: the format string
 * @flagPar: the parameter of format
 * Return: current s pointer
 */
char *get_modifier(char *s, format_fg *flagPar)
{
	switch (*s)
	{
	case 'h':
		flagPar->modifier |= SHORT;
		s++;
		break;
	case 'l':
		flagPar->modifier |= LONG;
		s++;
		break;
	}
	return (s);
}

/**
 * get_specifier - get the type of specifier
 * @s: the format string
 * @flagPar: the parameter of format
 * Return: 1 if there format
 * else 0
 */
int get_specifier(char *s, format_fg *flagPar)
{
	int i = 0;

	format_specifier specifiers[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_bin},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{"u", print_unsigned},
		{"p", print_address},
		{"r", print_rev},
		{"R", print_rot13},
		{"S", print_stringNonPrintable},
		{NULL, NULL}
	};
	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			(*flagPar).specifier = specifiers[i].func;
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * useModifier - useModifier
 * @num: number
 * @m_type: Number indicating the type to be casted
 *
 * Return: casted value
 */
long int useModifier(unsigned long int num, int m_type)
{
	if (m_type == LONG)
		return (num);
	else if (m_type == SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
