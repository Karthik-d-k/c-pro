/* Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. 
   In particular, itob(n,s,16) formats s as a hexadecimal integer in s.*/

#include <stdio.h>
#include <string.h>
#define LIMIT 100

void reverse(char s[]);
void itob(int n, char s[], int b);

int main()
{     
    int n = 43981;
	int b = 16;
    char s[LIMIT];
    
	itob(n, s, b);
    printf("Integer %d converted to a base %d character representation is = %s\n", n, b, s);
    
    return 0;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) 
        c = s[i], s[i] = s[j], s[j] = c;
}

void itob(int n, char s[], int b)
{
    int i, sign, x;
    
    if ((sign = n) < 0)                /* record sign */
        n = -(n + 1);                 /* make n positive (and add 1 to avoid overflow for INT_MIN)*/
    i = 0;
    do 
    {                                 /* generate digits in reverse order */
        x = n % b + '0';             /* get next digit */
		x = (x > 57) ? (x + 7) : x; /* Add 7 to make compatible for base > 10 */
		s[i++] = x;
    } while ((n /= b) > 0);        /* delete it */
    if (sign < 0)
	{
        s[i++] = '-';
		s[0]++;                   /* 0th element is Incremented by 1 to compensate for the addition that we did above */
	}
    s[i] = '\0';
    reverse(s);
}
