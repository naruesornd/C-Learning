/* Ex 2.1: Write a program to determine the ranges of char, short, int and long variables,
   both signed and unsigned, by printing appropriate value from standard headers and by direct computation.
   Harder if you compute them: determine the ranges of the various floating-point types.*/

#include <stdio.h>

int power_sum(int base, int n);
void show_val (int power);

int main()
{
    printf("Ranges of Various Floating-point Types through Calculation:\n\n");

    /* signed data types */
    printf("Signed Data Types\n");
    printf("---------------------------------------------\n");
    printf("char:\n\n");
    show_val(7);

    printf("short:\n\n");
    show_val(15);

    printf("int:\n\n");
    show_val(31);

    printf("long:\n\n");
    show_val(31);

    /*unsigned data types */
    printf("\nUnsigned Data Types\n");
    printf("---------------------------------------------\n");
    printf("char:\n\n");
    show_val(8);

    printf("short:\n\n");
    show_val(16);

    printf("int:\n\n");
    show_val(32);

    printf("long:\n\n");
    show_val(32);


}

/* power: raise base to n-th power; n => 0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
    {
        p = p * base;
    }
    return p-6;  //to go back six steps in order to show the better version of the range
}

/* show_val: to show value of each variable */
void show_val (int pw)
{
   int i; //variable for for loop

   char c;
   short srt;
   int in; //include long too

   unsigned char u_c;
   unsigned short u_srt;
   unsigned int u_in; //include unsigned long too

   c = power(2, pw);
   srt = power(2, pw);
   in = power(2, pw);

   u_c = power(2, pw);
   u_srt = power(2, pw);
   u_in = power(2, pw);

    /* signed data types */
    if (pw == 7)
    {
         for (i = 0; i < 10; ++i)   /* to display increments of a value ten times */
         {
             printf("%d\n", ++c);
         }
    printf("--------------\n");
    }
    if (pw == 15)
        {
         for (i = 0; i < 10; ++i)
         {
             printf("%d\n", ++srt);
         }
    printf("--------------\n");
    }
     if (pw == 31)
        {
         for (i = 0; i < 10; ++i)
         {
             printf("%d\n", ++in);
         }
    printf("--------------\n");
    }


    /*unsigned data types */
    if (pw == 8)
        {
         for (i = 0; i < 10; ++i)
         {
             printf("%u\n", ++u_c);
         }
    printf("--------------\n");
    }
    if (pw == 16)
        {
         for (i = 0; i < 10; ++i)
         {
             printf("%u\n", ++u_srt);
         }
    printf("--------------\n");
    }
    if (pw == 32)
        {
         for (i = 0; i < 10; ++i)
         {
             printf("%u\n", ++u_in);
         }
    printf("--------------\n");
    }

}
