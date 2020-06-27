/* Ex.2.5: Write the function any(s1,s2), which returns the first location in the string s1 where any character from the string s2 occurs,
   or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location) */

#include <stdio.h>

#define MAXLINE 1000


int getline(char line[],int maxline);
int any(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE], s2[MAXLINE];

    printf("s1: ");
    getline(s1, MAXLINE);

    printf("s2: ");
    getline(s2, MAXLINE);

    any(s1, s2);

    printf("First location is %d\n", any(s1, s2));



    return 0;
}

/* getLine function: read a line into s, return length */
int getline(char s[], int lim)
{
    /* for loop from getline function in Chapter 1: for (i=0; i <lim-1 && (c=getchar())!=EOF && c!='\n ; ++i) */

    int c, i;

    i = 0;
    c = 0;
    while (i < lim-1)
    {
        c = getchar();
        if (c == EOF)
        {
            lim = 0;
        }
        else if (c == '\n')
        {
            lim = 0;
        }
        else
        {
            s[i++] = c;
        }
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* any: returns the first location in s1 where any character from s2 occurs */
int any(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; ++i)
    {
        for (int j = 0; s2[j] != '\0'; ++j)  /* compares characters of s2 with s1[i] */
        {
            if (s1[i] == s2[j])          /* if a match is found, return the first character matched */
            {
                return i;
            }

        }
    }
    return -1;                           /* if not, return -1 */
}
