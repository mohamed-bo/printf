#include "main.h"

/**
 * convert - converter function
 * @number: number in decimal
 * @base: base
 * @flags: argument flags
 * Return: result in string
 */
char *convert(long int number, int base, int flags)
{
	static char *array;
	static char buffer[28];
	char sign = 0;
	char *current;
	unsigned long num = number;

	array = flags & LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	if (!(flags & UNSIGNED) && number < 0)
	{
		num = -number;
		sign = '-';

	}
	current = &buffer[27];
	*current = '\0';
	do	{
		*--current = array[num % base];
		num /= base;
	} while (num != 0);

	if (sign)
		*--current = sign;
	return (current);
}
