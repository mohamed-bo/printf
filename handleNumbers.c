#include "main.h"

/**
 * _putNumber - handle numbers
 * @c_u: current index
 * @b: to optimize printf
 * @f: the parameter of format
 * @l: length
 * @p: Pading char
 * @bc: first character
 * Return: counter
 */
int _putNumber(int c_u, char b[], format_fg *f,	int l, char p, char bc)
{
	int i, s = 1;

	if (f->precision == 0 && c_u == BUFF_SIZE - 2 && b[c_u] == '0')
	{
		if (f->width == 0)
			return (0);
		b[c_u] = p = ' ';
	}
	if (f->precision > 0 && f->precision < l)
		p = ' ';
	while (f->precision > l)
		b[--c_u] = '0', l++;
	if (bc != 0)
		l++;
	if (f->width > l)
	{
		for (i = 1; i < f->width - l + 1; i++)
			b[i] = p;
		b[i] = '\0';
		if (bc && p == ' ')
			b[--c_u] = bc;
		if (f->flags & F_MINUS && p == ' ')
		{
			return (write(1, &b[c_u], l) + write(1, &b[1], i - 1));
		}
		else if (!(f->flags & F_MINUS) && p == ' ')
		{
			return (write(1, &b[1], i - 1) + write(1, &b[c_u], l));
		}
		else if (!(f->flags & F_MINUS) && p == '0')
		{
			if (bc)
				b[--s] = bc;
			return (write(1, &b[s], i - s) + write(1, &b[c_u], l - (1 - s)));
		}
	}
	if (bc)
		b[--c_u] = bc;
	return (write(1, &b[c_u], l));
}
/**
 * handleUnsined - handleUnsined number
 * @current: current index
 * @buffer: to optimize
 * @flagPar: the parameter of format
 * Return: counter
 */
int handleUnsined(int current, char buffer[], format_fg *flagPar)
{
	int lenn = BUFF_SIZE - current - 1, i = 0;
	char paddinChar = ' ';

	if (flagPar->precision == 0 && current == BUFF_SIZE - 2 &&
	 buffer[current] == '0')
		return (0);
	if (flagPar->precision > 0 && flagPar->precision < lenn)
		paddinChar = ' ';
	while (flagPar->precision > lenn)
	{
		buffer[--current] = '0';
		lenn++;
	}
	if ((flagPar->flags & F_ZERO) && !(flagPar->flags & F_MINUS))
		paddinChar = '0';
	if (flagPar->width > lenn)
	{
		for (i = 0; i < flagPar->width - lenn; i++)
			buffer[i] = paddinChar;
		buffer[i] = '\0';
		if (flagPar->flags & F_MINUS)
		{
			return (write(1, &buffer[current], lenn) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[current], lenn));
		}
	}

	return (write(1, &buffer[current], lenn));
}
