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
    char s[MAXLINE];  // modified output
    char t[MAXLINE];  // original input

    getline(t, MAXLINE);

    escape(s,t);

    printf("Escape: %s\n", s);
}

/* getline: red a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim-1 && (c = getchar()) != EOF; ++i)
        s[i] = c;

    s[i] = '\0';
    return i;
}

/* escape: converts characters like tabs and newlines into visible sequences like \n and \t */
void escape(char s[], char t[])
{
    int i, j;

    for(i = j = 0; t[i] != '\0'; ++i){
        switch (t[i]){
        case '\n':         // newlines
            s[j] = '\\';
            j++;
            s[j] = 'n';
            j++;
            break;
        case '\t':        // tabs
            s[j] = '\\';
            j++;
            s[j] = 't';
            j++;
            break;
        default:         // other characters
            s[j] = t[i];
            j++;
            break;
        }
    }
    s[j] = '\0';        // termination of line
}
