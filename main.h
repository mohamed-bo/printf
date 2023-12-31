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

#define MINUS 1
#define PLUS 2
#define SPACE 4
#define HASH 8
#define ZERO 16
#define UNSI 32

#define SHORT 1
#define LONG 2
/**
 * struct parameters - parameters of format
 *
 * @flag: flag
 * @width: field width specified
 * @precision: field precision specified
 * @modifier: on if h_mod is specified
 * @l_mod: on if l_mod is specified
 * @specifier: function of specifier
 */
typedef struct parameters
{
	unsigned int flag;
	unsigned int width;
	unsigned int precision;
	unsigned int modifier;
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
int _putString(char *str);
int _putchar(int c);

/* convert_number.c module */
int print_bin(va_list agrument, format_fg *flagPar);
int print_oct(va_list agrument, format_fg *flagPar);
int print_hex(va_list agrument, format_fg *flagPar);
int print_HEX(va_list agrument, format_fg *flagPar);

/* convert.c module */
char *convert(long int num, int base, int flags);
long int useModifier(unsigned long int num, int m_type);
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
int printNonMinus(char *str, format_fg *flagPar);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif

