#include <stdio.h>

/* Sect 1.5.1-1: copy input to output: 1st version*/
int main()
{
    int c;

    c = getchar();
    while ( c !=EOF) {
        putchar(c);
        c = getchar();
    }

    return 0;
}
