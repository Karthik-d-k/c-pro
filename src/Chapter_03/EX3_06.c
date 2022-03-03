/* Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. 
   The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#define LIMIT 100
#define VERSION 2        /* change the version number to either 1 or 2 */

void reverse(char s[]);
void itoa_V01(int n, char s[]);
void itoa_V02(int n, char s[], int field_width);

int main()
{     
    int n = INT_MIN;
    int field_width = 20;
    char s[LIMIT];
    
    if (VERSION == 1)
    {
        itoa_V01(n, s);
        printf("'%s' (V01)\n", s);
    }
    else if (VERSION == 2)
    {
        itoa_V02(n, s, field_width);
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

/* itoa_V02: convert n to characters in s -> minimum field width is added as a third argument */
void itoa_V02(int n, char s[], int field_width)
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
    while (i < field_width)
        s[i++] = 32;          /* padded with blanks on the left to make it wide enough (i.e, field_width)*/
    s[i] = '\0';
    reverse(s);
}
