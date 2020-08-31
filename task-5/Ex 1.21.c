/* Ex 1.21: Write a program entab that replaces strings of blanks with the minimum number of tabs and blanks to achieve the same spacing.
Use the same stops as for detab . When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>

#define MAXLINE 1000  /* maximum characters of a line */
#define TABWIDTH 4  /* fixed tab stop */

char line[MAXLINE];    /* current input line */
char entline[MAXLINE];  /* entabbed line saved here */

int getline(void);
void entab(void);

int main()
{
    int len;  /* current line length */
    extern char line[MAXLINE];
    extern char entline[MAXLINE];

    while ((len = getline()) > 0)
    {
        entab();
        printf("Entab version:%s", entline);
    }
    return 0;
}

/* getline: reads a line, return line length */
int getline(void)
{
    int i, c;
    extern char line[];

    for (i = 0; i < MAXLINE-1 &&  (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
         line[i] = c;
         ++i;
    }
    line[i] = '\0';
    return i;
}

/* entab: replaces strings of blanks with tabs and blanks */
void entab(void)
{
    int i, j, spacecount;
    extern char line[], entline[];

    i = 0;
    j = 0;

    while ((entline[j] = line[i]) != '\0')
    {
        if (entline[j] == ' ')
        {
            spacecount++; /* increment counter for each space */
        }
        else
        {
            spacecount = 0; /* reset counter */
        }
        if (spacecount == TABWIDTH)
        {
            j = j + 3;
            entline[j] = '\t';
        }

        if (spacecount != TABWIDTH)
        {
            ++j;
        }
        ++i;
        spacecount = 0; /*reset counter */
        entline[j] = '\0'; /* termination of strings of characters */
    }
}

/* When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? */
/* A tab. */
