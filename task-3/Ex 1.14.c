#include <stdio.h>

#define MAXCHAR 127 /* maximum number of characters from 1 - 127 according to ASCII codes */
#define UNWANT  33  /* unwanted ASCII codes from 0 - 32 */
/* Ex 1.14: Write a program to print a histogram of the frequencies of different characters in its input. */

int main()
{
    int c, i, j;
    int character[MAXCHAR];
    for (i = UNWANT; i < MAXCHAR; ++i)
        character[i] = 0;

    while ((c = getchar()) != EOF)
        {
            if (c > UNWANT && c < MAXCHAR)
            {
                ++character[c];
            }
        }

    /* extra: printing heading of the histogram*/
    printf("\n\t\tHISTOGRAM OF THE FREQUENCIES OF DIFFERENT CHARACTERS IN ITS INPUT\n");

    /* printing the characters */
    for (i = UNWANT; i < MAXCHAR; ++i)
    {
        printf("|%c|", i);
        for ( j = 0; j < character[i]; ++j)
            putchar('x');

        putchar('\n');
    }
    return 0;

}
