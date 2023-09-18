#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%13.15d, %13.15i]\n", len, len);
    printf("Length:[%13.15d, %13.15i]\n", len2, len2);
    _printf("Negative:[%13.15d]\n", -762534);
    printf("Negative:[%13.15d]\n", -762534);
    _printf("Unsigned:[%13.15u]\n", ui);
    printf("Unsigned:[%13.15u]\n", ui);
    _printf("Unsigned octal:[%13.15o]\n", ui);
    printf("Unsigned octal:[%13.15o]\n", ui);
    _printf("Unsigned hexadecimal:[%13.15x, %13.15X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%13.15x, %13.15X]\n", ui, ui);
    _printf("Character:[%13.15c]\n", 'H');
    printf("Character:[%13.15c]\n", 'H');
    _printf("String:[%13.15s]\n", "I am a string !");
    printf("String:[%13.15s]\n", "I am a string !");
    _printf("Address:[%13.15p]\n", addr);
    printf("Address:[%13.15p]\n", addr);
    len = _printf("Percent:[%13.15%13.15]\n");
    len2 = printf("Percent:[%13.15%13.15]\n");
    _printf("Len:[%13.15d]\n", len);
    printf("Len:[%13.15d]\n", len2);
    _printf("Unknown:[%13.15r]\n");
    printf("Unknown:[%13.15r]\n");
    return (0);
}
