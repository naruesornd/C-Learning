/* ex 3.3: Write a function expand(s1, s2)  that expands shorthand notations like a-z in the strin s1
           into the equivalent complete list abc...xyz in s2. Allow for lettters of either case and digits,
           and be prepared to handle cases like a-b-c aand a-z0-9 and -a-z. Arrange that a leading or trailing
           -s is taken literally.  */

#include <stdio.h>

#define MAXLINE 100

int getline(char s[], int maxline);
void expand(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE], s2[MAXLINE];

    getline (s1, MAXLINE);

    expand (s1, s2);

    printf("\nexpand version:\n");
    printf("%s\n", s2);

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* expand: expand shorthand notations in s1 into equivalent complete list in s2 */
void expand(char s1[], char s2[])
{
    char c;
    int i, j;

    i = j = 0;
    while ((c = s1[i++]) != '\0'){            // collect a character from s[1]
        if (s1[i] == '-' && s1[i+1] >= c){
            i++;
            while (c < s1[i]){              // expand shorthand notations
            s2[j++] = c++;
            }
        }
        else
        s2[j++] = c;                        //copy the characters into s2
    }
    s2[j] = '\0';
}
