#include "main.h"

/**
 * print_buffer - using buff to limit write
 * @buffer: Array of char
 * @current: index of current
 */

void print_buffer(char buffer[], int *current)
{
	if (*current > 0)
		write(1, &buffer[0], *current);

	*current = 0;
}

/**
 * _printf - similar to printf of langauge c
 * @format: format to print
 * Return: length of printed characters
 */

int _printf(const char *format, ...)
{
	int i, counter = 0, paramsCount = 0;
	int current = 0;
	format_fg flagPar;
	va_list agruments;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(agruments, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[current++] = format[i];
			if (current == BUFF_SIZE)
				print_buffer(buffer, &current);
			counter++;
		}
		else
		{
			print_buffer(buffer, &current);
			paramsCount = get_flag_param(format, &flagPar, agruments, &i, buffer);
			if (paramsCount == -1)
				return (-1);
			counter += paramsCount;
		}
	}

	print_buffer(buffer, &current);
	va_end(agruments);

	return (counter);
}


