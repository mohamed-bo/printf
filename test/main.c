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
    _printf("test %.2c  \n","5");
    _printf("test %.2d  \n","4444");
    _printf("test %.2h  \n","5555");
    _printf("test %.2o  \n","4444");
    _printf("test %.2u  \n","5");
    return (0);
}
