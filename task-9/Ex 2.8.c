/* Ex 2.6: Write a function rightrot(x,n) that returns the value of the
integer x rotated to the right by n bit positions. */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);
int wordlength();
void showbin(int val);

int main()
{
    printf("Result: %u\n", rightrot(8, 2));
    showbin(0);
}

/* rigtrot: rotates x to the right by n bit positions */
unsigned rightrot (unsigned x, int n)
{
    int wordlength(void);
    unsigned right_bit; /* rightmost bit */

    right_bit = x << (wordlength() - n);
    x = x >> n;
    x = x | right_bit;

    return x;
}

/* wordlength:  computes the word length of the host machine */
int wordlength()
{
    int i;
    unsigned v = ~0;

    for(i = 1;(v = v >> 1) > 0; i++)
        ;
    return i;
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




