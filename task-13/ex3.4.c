/* ex 3.4: In a two's complement number representstion, our version off itoa does not handle the larget negativ number,
           that is, the value of n equal to -(2^(wordsize-1)). Explain why not. Modify it to turn that value correctly,
           regardless of the machine on which it runs. */

/* Explaination: the maximum value of int is  2147483647,so when the minimum of int, -2147483648, is inputed in the program,
                 Hence, when the minimum of int is converted to positive at n = -n, it will become 2147483648 which exceeds
                 the maximum of int*/

#include <stdio.h>

#define MAXLINE 1000

void itoa (int n, char s[]);
void reverse(char s[]);

int main()
{
    int value;
    char s[MAXLINE];

    value = -2147483648;

    printf("Intergers inputed: %d\n", value);

    itoa(value, s);

    printf("is equaivalent to %s", s);
}

/* itoa: convert n to characters in s (modified) */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign == n) > 0){
        n = -n;
    }
    i = 0;
    do{                         // generate digits in reverse order
        s[i++] = '0' - (n % 10);  // get next digit
    } while ((n /= 10) > 0);    // delete it
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
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
