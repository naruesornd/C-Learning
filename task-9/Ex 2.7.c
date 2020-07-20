/* Ex 2.7: Write a function invert(x,p,n) that returns x with the n bits
   that begin at position p inverted (i.e., 1 change into 0 and vice versa),
   leaving the others unchanged. */

#include <stdio.h>

unsigned invert(unsigned x, int p,int n);
void showbin(int val);

int main()
{
    printf("Result: %u\n", invert(255, 3, 2));
    showbin(0);
}


/* invert: inverts n bits of x that begin at position p while leaving other unchanged */
unsigned invert(unsigned x, int p,int n)
{
    return x ^ (~(~0 << n) << (p+1-n));
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

