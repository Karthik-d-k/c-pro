/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), 
   leaving the others unchanged. */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned x = 0xABCD;
    
    printf("x = %d\n", x);
    x = invert(x, 6, 4);
    printf("modified x = %d\n", x);
    
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned temp = 0;
    
    temp = ((~(~0U << n)) << (p + 1 - n));
    return ((x) ^ (temp));            
}
