/*Sect 2.3-1 */

#include <stdio.h>
#include <string.h>

/* strlen: return length of s */
int strlen(char s[])
{
    int i;

    i =0;
    while(s[i] != '\0')
        ++i;
    return i;
}

