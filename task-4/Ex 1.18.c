/* Ex 1.18: Write a program to remove trailing blanks
and tabs from each line of input, and to delete entirely blank lines. */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
int removetrial(char s[]);


int main()
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (removetrial(line) > 0)
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

/* removetrial: to remove trailing blanks and tabs from the character string s[] */
int removetrial(char s[])
{
    int i;

    i = 0;

    while ( s[i] != '\n')   /* find newline character */
    {
        ++i;
    }
    --i;   /* back off from '\n' */

    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
    {
        --i; /* removing trailing blanks and tabs */
    }

    if (i >= 0)  /* non-blank line */
    {
        ++i;
        s[i] = '\n';  /* put back newline character */
        ++i;
        s[i] = '\0';  /* terminate the string */
    }
    return i;
}

