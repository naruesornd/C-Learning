/* Ex 2.10: Rewrite the function lower, which converts upper case letters to lower case,
   with a conditional expression instead of if-else. */

#include <stdio.h>
int lower(char c);

int main()
{
    int c;

    while ((c = getchar())!=EOF)
    {
        putchar(lower(c));
    }
}

int lower(char c)
{
    return (c>='A' && c<='Z') ? c+'a'-'A' : c;
}
