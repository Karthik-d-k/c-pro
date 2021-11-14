/* Exercise 3-4. In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, 
   the value of n equal to -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#define LIMIT 100
#define VERSION 2        /* change the version number to either 1 or 2 */

void reverse(char s[]);
void itoa_V01(int n, char s[]);
void itoa_V02(int n, char s[]);

int main()
{     
    int n = INT_MIN;
    char s[LIMIT];
    
    if (VERSION == 1)
    {
        itoa_V01(n, s);
        printf("'%s' (V01)\n", s);
    }
    else if (VERSION == 2)
    {
        itoa_V02(n, s);
        printf("'%s' (V02)\n", s);
    }
    else
        printf("Entered version number is not correct\n");
    
    return 0;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) 
        c = s[i], s[i] = s[j], s[j] = c;
}

/* itoa_V01: convert n to characters in s */
void itoa_V01(int n, char s[])
{
    int i, sign;
    
    if ((sign = n) < 0)           /* record sign */
        n = -n;                   /* make n positive */
    i = 0;
    do 
    {                            /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* itoa_V02: convert n to characters in s -> handles the largest negative number, that is, the value of n equal to -(2^(wordsize-1)) */
void itoa_V02(int n, char s[])
{
    int i, sign;
    
    if ((sign = n) < 0)            /* record sign */
        n = -(n + 1);             /* make n positive (and add 1 to avoid overflow for INT_MIN)*/
    i = 0;
    do 
    {                             /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
	{
        s[i++] = '-';
		s[0]++;                /* 0th element is Incremented by 1 to compensate for the addition that we did above */
	}
    s[i] = '\0';
    reverse(s);
}

/* 
Reason itoa_V01 won't work for n = INT_MIN (-(2^(wordsize-1)))
--------------------------------------------------------------------------------------------------------
INT_MIN = -2147483648;
INT_MAX =  2147483647;
so when we do n = -n, overflow occurs, because n cannot store 2147483648 (It can only store 2147483647)
--------------------------------------------------------------------------------------------------------
*/
