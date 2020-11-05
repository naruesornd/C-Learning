/* Ex.2.4: Write an alternative version of squeeze(s1, s2) that deletes each character in s1 that matches any character
 in the string s2 */

#include <stdio.h>

#define MAXLINE 1000


int getline(char line[],int maxline);
void squeeze(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE], s2[MAXLINE];

    printf("s1: ");
    getline(s1, MAXLINE);

    printf("s2: ");
    getline(s2, MAXLINE);

    squeeze(s1, s2);

    printf("\nFunction squeeze in used: %s\n", s1);

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

/* squeeze: delete each char in s1 which is in s2 */
void squeeze(char s1[], char s2[])
{
#if 1
    int i;       /* variable for s1 */ //Kovbas. If you use such a sort of variable just in a for loop, you can initialize it there.
    int j;       /* variable for s2 */
    int k;       /* variable for storing i from s1 */

    k = 0;

    for (i = 0; s1[i] != '\0'; i++)    /* for initializing s1[i] */
    {
        for (j = 0; (s1[i] != s2[j]) && s2[j] != '\0'; ++j)  /* for checking each character in s2[j] against s1[i] character */
        ;
        if(s2[j] == '\0')   /* if s2 characters do not match any s1 characters, then this if statement works and s1[i] characters will be copied to s1[k] (resulting string), and if there is or are matches, if statement fails and s1[i] is not copied to s1[k] */
        {
            s1[k++] = s1[i];
        }
    }
     s1[k] = '\0';

#else // Kovbas. Consider it:
    int k = 0;       /* variable for storing i from s1 */

    for (int i = 0; s1[i] != '\0'; ++i)    /* for initializing s1[i] */
    {
    	int j;
        for (j; (s1[i] != s2[j]) && s2[j] != '\0'; ++j)  /* for checking each character in s2[j] against s1[i] character */
        ;
        if(s2[j] == '\0')   /* if s2 characters do not match any s1 characters, then this if statement works and s1[i] characters will be copied to s1[k] (resulting string), and if there is or are matches, if statement fails and s1[i] is not copied to s1[k] */
        {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
#endif
}
