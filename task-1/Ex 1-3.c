#include <stdio.h>
#include <stdlib.h>

/* print Celsius-Fahrenheit table
   for celsius = 0, 20, ..., 300; floating-point version */
int main()
{
    char  degree = 'C';
    printf("%3.0c", degree);
    degree = 'F';
    printf("\t%6.1c\n", degree);

    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius +32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
