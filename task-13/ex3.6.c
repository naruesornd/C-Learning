/* ex 3.6: Write a verion of itoa that accepts three arguement instead of two. The third arguement is a minimum field width;
           the converted number must be padded with blanks on the left if necesssary to make it wide enough. */
           
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

void itoa(int n, char s[],int b);
int getline (char line[], int maxline);
void reverse(char s[]);
int atoi(char s[]);


int main()
{
    int  value, width;
    char s[MAXLINE];

    width = 10;

    getline(s, MAXLINE);
    atoi(s);

    value = atoi(s);

    itoa(value, s, width);

    printf("itoa: %s\n", s);

    return 0;
}

/* itoa: converts the n to characters in s (added 3rd arguement: width) */
void itoa(int n, char s[], int w)
{
    int i, sign;

    if ((sign = n) < 0)         // record sign
        n = -n;                 // make n positive
    i = 0;
    do{                         // generate digits in reverse order
        s[i++] = n % 10 + '0';  // get next digit
    } while ((n /= 10) > 0);    // delete it
    if (sign < 0){
        s[i++] = '-';
    }
    while (i <= w){
        s[i++] = ' ';         // converted number padded with blanks
    }
    s[i] = '\0';
    reverse(s);
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

