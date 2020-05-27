/* Ex 1.19: Write a function reverse(s) that reverses the character string s.
   Use it to write a program that reverses its input a line at a time. */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
int reverse(char s[]);


int main()
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getline(line, MAXLINE)) > 0)
    {
        reverse(line);
        printf("Reverse version: %s", line);
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

/* reverse: reverse string s[] */
int reverse(char s[])
{
    int i;  /* index for last character of the string */
    int j;  /* index for first character of the string */
    char swap; /* tool for swapping characters */

    i = 0;   /* end of string s[] */

    while (s[i] != '\0')  /* find the end of string s */
    {
        ++i;
    }
    --i;  /* back off from '\0' to prevent the first character from becoming an end of string */
    if (s[i] == '\n')
    {
        --i;  /* back off from '\n' */
    }

    j = 0;  /* beginning of new string s[] */

    while (j < i)
    {
        swap = s[j];
        s[j] = s[i];   /* swapping characters site*/
        s[i] = swap;
        --i;  /* the last character moves to the beginning of the string */
        ++j;  /* the first character moves to the end of the string */
    }
}

