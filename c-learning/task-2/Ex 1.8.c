#include <stdio.h>

/* Ex 1.8: write a program to count blanks, tabs, and newlines */
int main()
{
    int c, nb, nt, nl;   /* nb = new blanks; nt = new tabs; nl = new lines */

    nb = 0;
    nt = 0;
    nl = 0;
    while((c = getchar()) != EOF)
    {
         if (c == ' ')
            ++nb; /* statement which presents an operator,++, which means increment by one */
         if (c == '\t')
            ++nt;
         if (c == '\n')
            ++nl;}
    printf("Blanks: %d\nTabs: %d\nNew Lines: %d\n", nb, nt, nl);
return 0;
}
