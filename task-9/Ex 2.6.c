/* Ex 2.6: Write a function setbits(x,p,n,y) that returns x with the
   n bits that begin at position p set to the rightmost n bits of y,
   leaving the other bits unchanged. */

#include <stdio.h>

unsigned setbits (unsigned x, int p,int n, unsigned y);
void showbin(int val);

int main()
{
    printf("Result: %u\n", setbits(255, 3, 2, 13));
    showbin(0);
}

/* setbits: set n bits of x that begin at position p set to the rightmost n bits of y, leaving the other bits changed. */
unsigned setbits (unsigned x, int p,int n, unsigned y)
{
    return (x & ~(~(~0 << n) << (p+1-n))) | (y & ~(~0 << n)) << (p+1-n);
}

/* showbin: shows binary number of the decimal given */
void showbin(int val)
{
    int i, j;

    printf("Enter an integer in decimal number system: ");
    scanf("%d", &val);
    printf("%d in binary number system is: ", val);

        for (i = (32-1); i >= 0; i--)  /* 32-1 because there is also position 0 */
        {
            j = val >> i;

            if (j & 1)
                printf("1");
            else
                printf("0");
        }
    printf("\n");
}


