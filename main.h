#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define LOWERCASE	1

#define F_MINUS 1
#define F_PLUS 2
#define F_SPACE 4
#define F_HASH 8
#define F_ZERO 16

#define S_SHORT 1
#define S_LONG 2

/**
 * struct parameters - parameters of format
 * @flags: which flags
 * @width: field width specified
 * @precision: field precision specified
 * @modifier: which modifier
 */

typedef struct parameters
{
	int flags;
	int width;
	int precision;
	int modifier;
} format_fg;

/**
 * struct fmt - Struct op
 *
 * @specifier: The format.
 * @func: The function associated.
 */
typedef struct format_spec
{
	char specifier;
	int (*func)(va_list, char[], format_fg *);
} format_specifier;

int _printf(const char *format, ...);
int useSpecifier(const char *s, int *format_i, va_list arguments,
 char buffer[], format_fg *flagPar);
char *convert(long int number, int base, int flags);
int get_flag_param(const char *s, format_fg *flagPar, va_list agruments, int *i, char buffer[]);
int print_int(va_list types, char buffer[], format_fg *flagPar);
int print_char(va_list types, char buffer[], format_fg *flagPar);
int print_string(va_list types, char buffer[], format_fg *flagPar);
int print_percent(va_list types, char buffer[], format_fg *flagPar);
int print_bin(va_list types, char buffer[], format_fg *flagPar);
int print_unsigned(va_list types, char buffer[], format_fg *flagPar);
int print_oct(va_list types, char buffer[], format_fg *flagPar);
int print_hex(va_list types, char buffer[], format_fg *flagPar);
int print_HEXUP(va_list types, char buffer[], format_fg *flagPar);
int printHexaDecimal(va_list types, int flag, format_fg *flagPar, char buffer[], char beforChar);
int print_stringNonPrintable(va_list types, char buffer[], format_fg *flagPar);
int print_address(va_list types, char buffer[], format_fg *flagPar);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_modifier(const char *format, int *i);
int print_rot13(va_list types, char buffer[], format_fg *flagPar);
int handlePointer(char buffer[], int ind, int length, char paddinChar,
 char beforChar, format_fg *flagPar);
int isPrint(char);
int addHex(char, char[], int);
int _putNumber(int ind, char buffer[], format_fg *flagPar,
	int length, char paddinChar, char beforChar);
int handleUnsined(int ind, char buffer[], format_fg *flagPar);
long int modifierFun(long int num, int size);
long int useMoidifier(unsigned long int num, int size);
int _isdigit(int c);
int _strlen(char *s);
int _putCharr(char c, char buffer[], format_fg *flagPar);
int print_rev(va_list types, char buffer[], format_fg *flagPar);
#endif
