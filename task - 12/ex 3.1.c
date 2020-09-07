/* ex 3-1: our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside). Write a version with only on test inside the loop and measure the difference in run-time */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
     int a[]={0,1,2,3,4,5,6,7,8,9,10};
     int v[]={2,4,6,7,9,29,45,46,49,50,51};
     printf("Position of a: %d\n", binsearch(4,a,10));
     printf("Position of v: %d\n", binsearch(46,v,10));

    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ...<= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    mid = (low + high) / 2;

    while (low <= high && x != v[mid])
    {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;

        mid = (low + high) / 2;
    }
        if (x == v[mid])   /* found match */
            return mid;
        else
            return -1; /* no match */
}

