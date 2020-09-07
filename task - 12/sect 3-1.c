/* Sect 3-1: Binary Function */
#include <stdio.h>

int main()
{
     int a[]={0,1,2,3,4,5,6,7,8,9,10};
     int v[]={2,4,6,7,9,29,45,46,49,50,51};
     printf("Position of a: %d\n",binsearch(4,a,10));
     printf("Position of v: %d\n",binsearch(46,v,10));


    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ...<= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
    if (x < v[mid])
        high = mid - 1;
    else if (x > v[mid])
        low = mid - 1;
    else   /* found match */
        return mid;
    }
    return -1; /* no match */
}


