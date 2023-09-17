#include <limits.h>
#include <stdio.h>
#include "../main.h"

int main(void)
{void *addr;
    int len = 0;
    int len2 = 0;
addr = (void *)0x7ffe637541f0;
    len = printf("Address:[%10p]\n", addr);
    len2 = _printf("Address:[%10p]\n", addr);
    printf("Length:[%d, %i]\n", len, len2);

    return (0);
}