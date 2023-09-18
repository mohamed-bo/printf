#include "main.h"

/**
 * _printf - simulation of printf library in c
 * @format: the format string
 * Return: number of char printed using write
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	va_list agruments;
	char *begin;
	char *format_c = (char *)format;

	format_fg flagPar;

	va_start(agruments, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (; *format_c; format_c++)
	{
		init_params(&flagPar, agruments);
		if (*format_c != '%')
		{
			counter += _putchar(*format_c);
		}
		else
		{
			begin = format_c;
			format_c++;
			format_c = get_flag_param(format_c, &flagPar, agruments);
			if (!flagPar.specifier)
				counter += printRange(begin, format_c,
										 flagPar.l_mod || flagPar.h_mod ? format_c - 1 : 0);
			else
				counter += flagPar.specifier(agruments, &flagPar);
		}
	}
	_putchar(EXIT);
	va_end(agruments);
	return (counter);
}
