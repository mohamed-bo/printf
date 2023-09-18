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
	char *array = flags & LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	static char buffer[25];
	unsigned long num = flags & UNSIGNED && number < 0 ? -number : number;
	char sign = flags & UNSIGNED && number < 0 ? '-' : 0;
	char *current;

	current = &buffer[24];
	*current = '\0';
	do	{
		*--current = array[num % base];
		num /= base;
	} while (num != 0);
	if (sign)
		*--current = sign;
	return (current);
}
