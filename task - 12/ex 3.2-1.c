/* ex 3.2-1: Write a function escape(s,t) that converts characters lie newline
   and tab into visible escape sequences like \n and \t
   as it copies the string t to s. Use a switch.
   Write a function for the other direction as well,
   converting escape sequences into the real character */

#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);
int getline (char line[], int maxline);

int main()
{
    char s[MAXLINE];
    char t[MAXLINE];

    getline(t, MAXLINE);

    escape(s,t);

    printf("%s", s);
}

/* getline: red a line into s, return length */
int getline(char s[]; int lim)
{
    int c, i;

    for(int i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* escape: converts characters like tabs and newlines into visible sequences like \n and \t */
void escape(char s[], char t[])
{
    int i, j;

    for(i = j = 0; t[i] != '/0'; i++)
        switch (t[i]){
        case '\n':            //newline
            s[j] = '\\';
            j++;
            s[j] = 'n';
            break;
        case '\t':            //tab
            s[j] = '\\';
            j++;
            s[j] = 't';
            break;
        default:             //all the rest characters
            s[j] = t[i];
            break;
        }
        ++j;
        ++i;
}
