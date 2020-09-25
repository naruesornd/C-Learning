/* ex 3.5: Write the function itob(n,s,b) that converts the integer into a base b characcter representation
           in string s. In particular, itob(n,s,16) formats n as a hexdecimal integer in s. */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

void itob(int n, char s[],int b);
int getline (char line[], int maxline);
void reverse(char s[]);
int atoi(char s[]);


int main()
{
    int  value, base;
    char s[MAXLINE];

    base = 16;

    getline(s, MAXLINE);
    atoi(s);

    value = atoi(s);

    itob(value, s, base);

    printf("itob: %s\n", s);

    return 0;
}

/* itob: converts the integer n into a base b character representation in the string s */
void itob(int n, char s[],int b)
{
    int i, j, sign;

    if ((sign = n) < 0)         // record sign
        n = -n;                 // make n positive
    i = 0;
    do{             // generate digits in reverse order
        j = n % b;
        s[i++] = (j <= 9)? j + '0': j + 'a' - 10;  // get next digit
    }while ((n /= b) > 0);        // delete it
    if (sign < 0){
        s[i++] = '-';
        }
    s[i] = '\0';
    reverse (s);
}

/* getline: red a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim-1 && (c = getchar()) != EOF; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* reverse: reverse characters in s */
void reverse(char s[])
{
    int i;      // index for last character of the string
    int j;      // index for first character of the string
    char swap;  // keyword for swapping characters

    i = 0;      // end of the string s[]

    while (s[i] != '\0'){
        ++i;
    }
    --i;        // back off from '\0' to prevent the first character from becoming an end of string

    if (s[i] == '\n'){
        --i;    // back off from '\n'
    }

    j = 0;      // beginning of new string s[]

    while (j < i){
        swap  = s[j];
        s[j] = s[i];        // swapping of characters take place here
        s[i] = swap ;
        --i;    // the last character moves to the beginning of the string
        ++j;    // the first character moves to the end of the string
    }
}

/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}
