#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAXLENGTH 11  /* maximum word length */

/* Ex. 1.13: Write a program to print a histogram of the lengths of words in its input. */

int main()
{
    int c, i, j;
    int state; /* a flag to state whether we are inside or outside the word */
    int nc; /* number of characters in a word */
    int wordlen[MAXLENGTH]; /* count the number of words of a certain length we insert*/

    state = IN;
    nc = 0;

    for(i = 0; i < MAXLENGTH; ++i)
        wordlen[i] = 0;

    while((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
            {
                if (state == OUT)
                {
                    if (nc > 0 && nc < MAXLENGTH)
                    {
                        ++wordlen[nc];
                    }
                }
                state = IN;
                    nc = 0;
            }
            else
                {
                    ++nc;
                    state = OUT;
                }
    }

    /* For printing the horizontal histogram */
    for(i = 1; i < MAXLENGTH; ++i)
    {
        printf("|%2d|", i);
        for(j = 0; j < wordlen[i]; ++j)
            putchar('x');

        putchar('\n');
    }
    return 0;
}
