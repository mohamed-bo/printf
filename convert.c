#include "main.h"

/**
 * convert - converter function
 * @number: number in decimal
 * @base: base
 * @flags: argument flags
 * Return: result in string
 */
char *convert(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}