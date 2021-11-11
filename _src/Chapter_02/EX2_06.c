/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, 
   leaving the other bits unchanged. */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned x = 0x00F0;
    unsigned y = 0x0002;
    
    printf("x = %d\ny = %d\n", x, y);
    x = setbits(x, 6, 4, y);
    printf("modified x = %d\n", x);
    
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned temp = 0;
    
    temp = x & ~((~(~0 << n)) << (p + 1 - n));
    return ((temp) | (y << (p + 1 - n)));            
}

/* 

Example snippet walkthrough.
----------------------------
x = 0x00F0 =          0000 0000 1111 0000
y = 0x0002 =          0000 0000 0000 0010
p = 6
n = 4
temp =                0000 0000 1000 0000     --> sets n bits to 0 from p, unaltered elsewhere.
(y << (p + 1 - n)) =  0000 0000 0001 0000     --> shifts rightmost n bits of y towards p.   
output =              0000 0000 1001 0000     --> logical or previous 2 steps gives us output.  
 
*/
