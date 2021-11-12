/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions. */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
    unsigned x = 0xFFFF;
    
    printf("x = %d\n", x);
    x = rightrot(x, 4);
    printf("modified x = %d\n", x);
    
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    return (x >> n);            
}
