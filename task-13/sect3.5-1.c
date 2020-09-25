/* sect 3.5-1: atoi (version 2) */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int atoi(char s[]);
int getline (char line[], int maxline);

int main()
{
    char s[MAXLINE];  // current line input

    getline(s, MAXLINE);

    atoi(s);

    printf("atoi: %s\n", s);
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim-1 && (c = getchar()) != EOF; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

