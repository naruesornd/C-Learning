#include <stdio.h>

#define MAXLINE 1000    /* maximum characters of a line */
#define TABWIDTH 4      /* fixed tab size */

int getline(char line[], int maxline);
int detab(char to[], char from[]);

int main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */
    char dtline[MAXLINE];    /* detabed line saved here */

    while ((len = getline(line, MAXLINE)) > 0) {
        detab(dtline, line);
        printf("Detab version:%s", dtline);
    }
    return 0;
}

/* getline: reads a line s, return line length */
int getline(char s[], int lim)
{
    int i, c;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        {
            s[i] = c;
            ++i;
        }
    s[i] = '\0';
    return i;
}

/* detab: replaces tabs with blanks */
int detab(char to[], char from[])
{
    int i, j, n;

    i = j = n = 0;

    while ((to[j] = from[i]) != '\0')
    {
        if (to[j] == '\t')
        {
              for (n = 0; n < TABWIDTH; ++n, ++j)
                to[j] = ' ';
        }
        else
        {
            ++j;
        }
        ++i;
    }
}
