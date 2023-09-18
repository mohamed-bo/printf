#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{void *addr;
    int len = 0;
    int len2 = 0;
addr = (void *)0x7ffe637541f0;
len2 = _printf("Address:[%+10.30p]\n", addr);
    
    printf("Length:[%d, %i]\n", len, len2);
_printf("test%+*.1ca\n",10,"1");
_printf("test%+ .*lba\n",10,7);
    _printf("test %+-20.5ia\n",-44);
        _printf("test %2.2s  \n","assdfefsafuihua");
    _printf("test %5.7R  \n","aaaabbbbb");
    _printf("test %.8o  \n",83);
    _printf("test %.8u  \n",-40);
    return (0);
}