#include "main.h"
/**
 * useSpecifier - use spicifier
 * @s: format
 * @arguments: agrument pointer
 * @format_i: current index.
 * @buffer: to optimize printf.
 * @flagPar: the parameter of format
 * Return: number of printed;
 */
int useSpecifier(const char *s, int *format_i, va_list arguments,
	char buffer[], format_fg *flagPar)
{
	int i, counter = -1;
	int stepsSkipped = 0;
	format_specifier specifiers[] = {
		{'c', print_char}, {'s', print_string},	{'%', print_percent},
		{'d', print_int}, {'i', print_int},	{'b', print_bin},
		{'o', print_oct}, {'x', print_hex},	{'X', print_HEXUP},
		{'u', print_unsigned}, {'p', print_address}, {'r', print_rev},
		{'R', print_rot13},
		{'S', print_stringNonPrintable},
		{'\0', NULL}
	};
	for (i = 0; specifiers[i].specifier != '\0'; i++)
		if (s[*format_i] == specifiers[i].specifier)
			return (specifiers[i].func(arguments, buffer, flagPar));
	if (specifiers[i].specifier == '\0')
	{
		if (s[*format_i] == '\0')
			return (-1);
		stepsSkipped += write(1, "%%", 1);
		if (s[*format_i - 1] == ' ')
			stepsSkipped += write(1, " ", 1);
		else if (flagPar->width)
		{
			--(*format_i);
			while (s[*format_i] != ' ' && s[*format_i] != '%')
				--(*format_i);
			if (s[*format_i] == ' ')
				--(*format_i);
			return (1);
		}
		stepsSkipped += write(1, &s[*format_i], 1);
		return (stepsSkipped);
	}
	return (counter);
}
/**
 *_strlen -  function that returns the length of a string.
 * @s: string value
 *Return: returns the length of a string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}
