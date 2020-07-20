/* Ex. 2.9: In a two's complement number system, x &= (x-1) deletes the right most 1-bit in x.
Explain why. Use this observation to write  faster version of bitcount. */

#include <stdio.h>

int bitcount(unsigned x);
void showbin(int val);

int main ()
{
    printf("Result: %u bits\n", bitcount(120));
    showbin(0);
}

/* bitcount: counts 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;

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
