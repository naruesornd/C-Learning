#include <stdio.h>

/* Ex 1.9: write a program to copy its input to its output,
   replacing each string of one or more blanks by a single blank */
int main()
{
    int c, pc;   /* c = character and pc = previous character */

    pc = 0;
    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            if(pc != c)  /* c == ' ' */
            {
                putchar(c);
            }
        }
        if(c != ' ')
        {
            putchar(c);
        }
        pc = c;  /* To give output replacing each string of one or more blanks by a single blank */
    }

    return 0;
}




