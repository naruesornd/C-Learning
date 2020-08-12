/* Sect 2.11: prints n elements of an array, 10 per line, with each column separated one blank,
and with each line (including the last)  terminated by a newline. */

#include <stdio.h>

int main()
{
    int i, n;
    int a[9];

    //i = 9;
    n = 10;
    for (i= 0; i < n; i++)
        printf("%6d%c", a[i], (i%10==9 || i==n-1) ? '\n' : ' ');
}
