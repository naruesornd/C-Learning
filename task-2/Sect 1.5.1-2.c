#include <stdio.h>

/* Sect 1.5.1-2: copy input to output; 2nd version*/
int main()
{
    int c;

    while (( c = getchar()) != EOF)
    putchar(c);

    return 0;
}
