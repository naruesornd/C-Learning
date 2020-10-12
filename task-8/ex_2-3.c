/* Ex 2.3: Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X)
   into its equivalent integer value. The allowable digits are 0 through 9, a through f,and A through F. */

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[],int maxline);
int htoi(char s[]);


int main()
{
    char line[MAXLINE];  /* string of hexadecimal digits (including an optional 0x or 0X) */
    int int_value;           /* equivalent integer value */

    getline(line, MAXLINE);
    int_value = htoi(line);

    printf("Hexadecimal digits: %s", line); //Kovbas. I see you want to output  hex number. Try to do it correctly, because now you output the whole line, not only hexadigital number from it.
    printf("Integer value: %d\n", int_value);

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

/* htoi: converts hexadecimal digits into integer */
int htoi(char s[])
{
#if 0 //Kovbas. If you want to force to work the first part of #if just replace 0 by 1
    enum boolean {NO, YES};
    int hex_digit;                 /* for storing each digit in hexadecimal */
    int i;
    int in_hex;                    /* a flag to see whether a hexadecimal is being looked */
    int n;                         /* for storing converted hexadecimal number */

    i = 0;
    if( s[i] == '0')        /* if statement to include 0x or 0X*/
    {
        ++i;
        if(s[i] == 'x' || s[i] == 'X')
        {
            ++i;
        }
    }

    in_hex = YES; //Kovbas. I think it is redundant, because if a line has not HEX characters, you can stop to process the line and return a line of hex and its decimal value
    for(n = 0; in_hex == YES; ++i)      /* for loop to identify hexidecimal digits and convert them */
    {
        if(s[i] >= '0' && s[i] <='9')
        {
            hex_digit= s[i] - '0';
        }
        else if(s[i] >='a' && s[i] <='f')
        {
             hex_digit= s[i] -'a' + 10;
        }
        else if(s[i] >='A' && s[i] <='F')
        {
            hex_digit = s[i] -'A' + 10;
        }
        else          /* Apart from 0 through 9, a through f,and A through F will not be considered */
        {
            in_hex = NO;
        }
        if(in_hex == YES)     /* Calculation take place here */
        {
            n = 16 * n + hex_digit;
        }
    }
    return n;
#else
    int hex_digit;                 /* for storing each digit in hexadecimal */
    int i;
    int res;                         /* for storing converted hexadecimal number */

    i = 0;
    if( s[i] == '0')        /* if statement to include 0x or 0X*/
    {
        ++i;
        if(s[i] == 'x' || s[i] == 'X')
        {
            ++i;
        }
    }

    for(res = 0; ; ++i)      /* for loop to identify hexidecimal digits and convert them */
    {
        if(s[i] >= '0' && s[i] <='9')
        {
            hex_digit= s[i] - '0';
        }
        else if(s[i] >='a' && s[i] <='f')
        {
             hex_digit= s[i] -'a' + 10;
        }
        else if(s[i] >='A' && s[i] <='F')
        {
            hex_digit = s[i] -'A' + 10;
        }
        else          /* Apart from 0 through 9, a through f,and A through F will not be considered */
        {
            break;
        }
        /* Calculation take place here */
        res = 16 * res + hex_digit;
    }
   	return res;
#endif
}

