/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions. */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);
int unsignedlength(void);

int main()
{
    unsigned x = 99;
    
    printf("x = %d\n", x);
    x = rightrot(x, 5);
    printf("modified x = %i\n", x);
    
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
	int length = unsignedlength();
	printf("bit length of x = %d\n", length);
	
    return ((x >> n) | (((x) & (~(~0 << n))) << (length - n)));            
}

/* bitlength: count no of bits in x */
int unsignedlength(void)
{
	int b;
	unsigned y;
	
	y = (~0);					  /* sets every bit of y to 1*/
	for (b = 0; y != 0; y >>= 1)
		b++;

	return b;
}
