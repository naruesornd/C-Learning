/* Ex 1.17: Write a program to print all input lines that are longer than 80 characters */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define MAXCHAR 80   /* maximum characters */

int getline(char line[], int maxline);

int main()
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */

    //while ((len = getline(line, MAXLINE)) > 0)
    while ((len = getline(line, MAXLINE)) > MAXCHAR)
    {
        //if (len > MAXCHAR)
            {
               printf("Line Contents: %s", line);
            }
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


