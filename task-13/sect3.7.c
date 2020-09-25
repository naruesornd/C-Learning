#include <stdio.h>

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
    int n;

    for (n = strlen(s)-1; n >=; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
        s[n+1] = '\0';
        return n;;
}
