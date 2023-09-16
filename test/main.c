#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
 _printf("test %.8s  \n","4444");
    _printf("test %.8c  \n","5");
    _printf("test %.8d  \n",-5);
    _printf("test %.8h  \n",55);
    _printf("test %.8o  \n",83);
    _printf("test %.8u  \n",-40);
    return (0);
}
