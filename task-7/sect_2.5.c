/*Sect 2.5: to observe how modulus operator "%" works */

#include <stdio.h>

int main()
{
    int year = 360;

    while(year <= 500)
    {
        if ((year % 4 == 0 && year % 100 !=0) || year % 400 == 0)
        	printf("%d is a leap year\n", year);
        else
        	printf("%d is not a leap year\n", year);
        year = year + 20;
    }
     return 0;
}
