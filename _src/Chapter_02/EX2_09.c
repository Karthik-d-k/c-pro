/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. 
   Use this observation to write a faster version of bitcount. */

#include <stdio.h>
#define VERSION 2    /* change the version number to either 1 or 2 */

int bitcount_V01(unsigned x);
int bitcount_V02(unsigned x);

int main()
{
    int x = 0xF9F5;      
    int len_V01, len_V02;
    
    if (VERSION == 1)
    {
        len_V01 = bitcount_V01(x);
        printf("bit count by V01 : %d\n", len_V01);
    }
    else if (VERSION == 2)
    {
        len_V02 = bitcount_V02(x); 
        printf("bit count by V02 : %d\n", len_V02);
    }
    else
        printf("Entered version number is not correct\n");
    
    return 0;
}

/* bitcount_V01: count 1 bits in x */
int bitcount_V01(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;

	return b;
}

/* bitcount_V02: count 1 bits in x -> faster version to bitcount_V01 */
int bitcount_V02(unsigned x)
{
	int b;
	for (b = 0; x != 0; x &= (x- 1))
		b++;

	return b;
}
