/* Ex 2.1: Write a program to determine the ranges of char, short, int and long variables,
   both signed and unsigned, by printing appropriate value from standard headers and by direct computation.
   Harder if you compute them: determine the ranges of the various floating-point types.*/

#include <stdio.h>

int power_sum(int base, int n);

int main()
{
   /* unsigned variables */

   int i;

   /* unsigned char */
   printf("unsigned char\n");
   i = 8;
   unsigned char var_c = power_sum(2, i);
   for (i = 2; i < 10; ++i)
   {
       printf("%d\n", var_c++);
   }
   printf("\n");

   /* unsigned short */
   printf("---------------------------------------------------------\n");
   printf("unsigned short\n");
   i = 16;
   unsigned short var_srt = power_sum(2, i);
   for (i = 2; i < 10; ++i)
   {
       printf("%d\n", var_srt++);
   }
   printf("\n");

   /* unsigned int */
   printf("---------------------------------------------------------\n");
   printf("unsigned int\n");
   i = 32;
   unsigned int var_int = power_sum(2, i);
   for (i = 2; i < 10; ++i)
   {
       printf("%u\n", var_int++);
   }
   printf("\n");

   /* unsigned long */
   printf("---------------------------------------------------------\n");
   printf("unsigned long\n");
   i = 32;
   unsigned int var_long = power_sum(2, i);
   for (i = 2; i < 10; ++i)
   {
       printf("%u\n", var_long++);
   }
   printf("\n");


   /* signed variables */

   /* signed char */
   printf("---------------------------------------------------------\n");
   printf("signed char\n");
   i = 6;
   signed char var_sg_c = power_sum(2, i);
   for (i = 2; i < 10; ++i)
   {
       printf("%d\n", var_sg_c++);
   }
   printf("\n");

   /* signed short */
   printf("---------------------------------------------------------\n");
   printf("signed short\n");
   i = 14;
   signed short var_sg_srt = power_sum(2, i);
   for (i = 2; i < 10; ++i)
   {
       printf("%d\n", var_sg_srt++);
   }
   printf("\n");

   /* signed int */
   printf("---------------------------------------------------------\n");
   printf("signed short\n");
   i = 30;
   signed int var_sg_int = power_sum(2, i);
   for (i = 2; i < 10; ++i)
   {
       printf("%d\n", var_sg_int++);
   }
   printf("\n");

   /* signed long */
   printf("---------------------------------------------------------\n");
   printf("signed long\n");
   i = 30;
   signed long var_sg_long = power_sum(2, i);
   for (i = 2; i < 10; ++i)
   {
       printf("%ld\n", var_sg_long++);
   }
   printf("\n");
}

/* power_sum: raise base to n-th power and sum up; n => 0 */
int power_sum(int base, int n)
{
printf("\nit is n which was i, when main invoked the func: %d\n\n", n);
    int i, p, sum;

    p = 1;
    sum = 0;
    for (i = 1; i <= n ; ++i)
    {
        p = p * base;
        sum = sum + p;
    }
    sum = sum - 2;
    return sum;
}
