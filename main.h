#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define EXITT -1
#define LOWERCASE	1
#define UNSIGNED	2

/**
 * struct parameters - parameters of format
 *
 * @unsign: flag if unsigned value
 * @plus: on if plus specified
 * @minus: on if _flag specified
 * @hashtag: on if _flag specified
 * @zero: on if _flag specified
 * @space: on if hashtag specified
 * @width: field width specified
 * @precision: field precision specified
 * @h_mod: on if h_mod is specified
 * @l_mod: on if l_mod is specified
 * @specifier: function of specifier
 */
typedef struct parameters
{
	unsigned int unsign;
	unsigned int plus;
	unsigned int minus;
	unsigned int hashtag;
	unsigned int zero;
	unsigned int space;
	unsigned int width;
	unsigned int precision;
	unsigned int h_mod;
	unsigned int l_mod;
	int (*specifier)(va_list agrument, struct parameters *flagPar);
} format_fg;

/**
 * struct specifier - Struct of specifier
 *
 * @specifier: type of specifier
 * @func: The function associated with this specifier
 */
typedef struct specifier
{
	char *specifier;
	int (*func)(va_list, format_fg *);
} format_specifier;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* convert_number.c module */
int print_bin(va_list agrument, format_fg *flagPar);
int print_oct(va_list agrument, format_fg *flagPar);
int print_hex(va_list agrument, format_fg *flagPar);
int print_HEX(va_list agrument, format_fg *flagPar);

/* convert.c module */
char *convert(long int num, int base, int flags);

/* flag.c module */
void init_params(format_fg *flagPar, va_list agruments);
char *get_flag_param(char *s, format_fg *flagPar, va_list agruments);
int get_flag(char *s, format_fg *flagPar);
char *get_width(char *s, format_fg *flagPar, va_list agrument);
char *get_precision(char *p, format_fg *flagPar, va_list agrument);
char *get_modifier(char *s, format_fg *flagPar);
int get_specifier(char *s, format_fg *flagPar);

/* print_normalFlags.c module */
int print_char(va_list agrument, format_fg *flagPar);
int print_int(va_list agrument, format_fg *flagPar);
int print_string(va_list agrument, format_fg *flagPar);
int print_percent(va_list agrument, format_fg *flagPar);
int print_unsigned(va_list agrument, format_fg *flagPar);
int print_address(va_list agrument, format_fg *flagPar);
int print_stringNonPrintable(va_list agrument, format_fg *flagPar);

/* print_utils.c module */
int _isdigit(int c);
int _strlen(char *s);
int printRange(char *begin, char *stop, char *except);
int print_rev(va_list agrument, format_fg *flagPar);
int print_rot13(va_list agrument, format_fg *flagPar);
int print_number(char *str, format_fg *flagPar);
int print_number_right_shift(char *str, format_fg *flagPar);
int print_number_left_shift(char *str, format_fg *flagPar);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif

