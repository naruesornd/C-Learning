/* Ex 2.2: Write a loop equivalent to the for loop above without using && or || */
#include <stdio.h>

#define MAXLINE 1000

int getline(char line[],int maxline);
void copy(char to[],char from[]);


int main()
{
    int len,max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while((len = getline(line,MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest,line);
        }
    }
    if (max > 0)
        printf("Longest line: %s", longest);

    return 0;
}

/* getLine function: read a line into s, return length */
int getline(char s[], int lim)
{
    /* for loop from getline function in Chapter 1: for (i=0; i <lim-1 && (c=getchar())!=EOF && c!='\n ; ++i) */

    int c, i;

    c = 0;
    i = 0;
    while (i < lim-1)
    {
        c = getchar();
        if (c == EOF)
        {
            lim = 0;
            // Kovbas. consider to use here break;
        }
        else if (c == '\n')
        {
            lim = 0;
            // Kovbas. consider to use here break;
        }
        else
        {
            s[i++] = c;
        }
    }
/* Kovbas. I think this block is redundant, because usually a line means symbols fron the line's beginning to end of line symbol, here it is \n
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
*/
    s[i] = '\0';

    return i;

}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[],char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
    ++i;
}
