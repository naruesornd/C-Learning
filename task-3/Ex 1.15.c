#include <stdio.h>

float celsius(float fahr);

/* Ex 1.15: Rewrite the temperature conversion program of Section 1.2 to use a function for conversion */
int main()
{
    /* printing the headings: Fahr and Cels */
    char fdegree[] = "Fahr";
    printf("%3s", fdegree);
    char cdegree[] = "Cels";
    printf("\t%6s\n", cdegree);

    float fahr;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper)
        {
        printf("%3.0f\t%6.1f\n", fahr, celsius(fahr));
        fahr = fahr + step;
        }
    return 0;
}

/*  celsius: convert fahr into celsius */
float celsius(float fahr)
{
    float c;

    c = (5.0/9.0) * (fahr-32);
    return c;
}
