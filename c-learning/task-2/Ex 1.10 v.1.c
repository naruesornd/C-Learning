#include <stdio.h>

/* Ex1.10: Write a program to copy it input to its output, replacing each tab by \t, each backspace by\b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way. */
int main()
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        if(c == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        if(c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        if(c !='\t')
        if(c != '\b')
        if(c != '\\')
        {
            putchar(c);
        }
    }

    return 0;
}






