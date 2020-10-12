#include <stdio.h>

/* Sect 1.5.2-1: count characters in input; 1st version */
int main()   
{
    long nc;      
    nc = 0;   
    while (getchar() != EOF) 
        ++nc; /* statement which presents an operator,++, which means increment by one */
    printf("%1d\n",nc); 

return 0; 
} 
