/* Ex 2.1: Write a program to determine the ranges of char, short, int and long variables,
   both signed and unsigned, by printing appropriate value from standard headers and by direct computation.
   Harder if you compute them: determine the ranges of the various floating-point types.*/

#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Ranges of Various Floating-point Types from Standard Headers: \n\n");

    /* signed data types */
    printf("Signed Data Types\n");
    printf("---------------------------------------------\n");
    printf("Minimum char  = %d\n", SCHAR_MIN);
    printf("Maximum char  = %d\n", SCHAR_MAX);
    printf("Minimum short = %d\n", SHRT_MIN);
    printf("Maximum short = %d\n", SHRT_MAX);
    printf("Minimum int   = %d\n", INT_MIN);
    printf("Maximum int   = %d\n", INT_MAX);
    printf("Minimum long  = %ld\n", LONG_MIN);
    printf("Maximum long  = %ld\n", LONG_MAX);
    printf("\n");

    /*unsigned data types */
    printf("Unsigned Data Types\n");
    printf("---------------------------------------------\n");
    printf("Maximum char  = %u\n", UCHAR_MAX);
    printf("Maximum short = %u\n", USHRT_MAX);
    printf("Maximum int   = %u\n", UINT_MAX);
    printf("Maximum long  = %lu\n", ULONG_MAX);
}
