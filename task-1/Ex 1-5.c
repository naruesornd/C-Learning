#include <stdio.h>
#include <stdlib.h>

/* print Fahrenheit-Celsius table
   from fahr = 300, 280, 260, ... */
int main()
{
    char degree = 'F';
    printf("%3c", degree);
    degree = 'C';
    printf("\t%6.1c\n", degree);

    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));

    return 0;
}
