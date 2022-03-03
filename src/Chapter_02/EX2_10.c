/* Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else. */

#include <stdio.h>
#define VERSION 2    /* change the version number to either 1 or 2 */

int lower_V01(int c);
int lower_V02(int c);

int main()
{
    int c = 'Z';      
    int low_V01, low_V02;
    
    if (VERSION == 1)
    {
        low_V01 = lower_V01(c);
        printf("lower case of %c if %c (V01)\n", c, low_V01);
    }
    else if (VERSION == 2)
    {
        low_V02 = lower_V02(c); 
        printf("lower case of %c if %c (V02)\n", c, low_V02);
    }
    else
        printf("Entered version number is not correct\n");
    
    return 0;
}

/* lower_V01: convert c to lower case; ASCII only */
int lower_V01(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

/* lower_V02: convert c to lower case; ASCII only w/0 if-else, using conditionals */
int lower_V02(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : (c);
}
