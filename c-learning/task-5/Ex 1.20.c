/* Ex 1.20: Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop.
   Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter? */
#include <stdio.h>

#define MAXLINE 1000    /* maximum characters of a line */
#define TABWIDTH 4      /* fixed tab stop */

char line[MAXLINE];    /* current input line */
char dtline[MAXLINE];  /* detabbed line saved here */

int getline(void);
void detab(void);

int main()
{
    int len;          /* current line length */
    extern char line[MAXLINE];
    extern char dtline[MAXLINE];

    while ((len = getline()) > 0)
        {
            detab();
            printf("Detab version:%s", dtline);
        }
    return 0;
}

/* getline: reads a line, return line length */
int getline(void)
{
    int i, c;
    extern char line[];

    for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
        {
            line[i] = c;
            ++i;
        }
    line[i] = '\0';
    return i;
}

/* detab: replaces tabs with blanks */
void detab(void)
{
    int i, j, n;
    extern char line[], dtline[];

    i = 0;
    j = 0;

    while ((dtline[j] = line[i]) != '\0')
    {
        if (dtline[j] == '\t')
        {
              for (n = 0; n < TABWIDTH; ++n, ++j)
                dtline[j] = ' ';
        }
        else
        {
            ++j;
        }
        ++i;
    }
}

/* Should n be a variable or a symbolic parameter? */
/* n is a symbolic parameter. */
