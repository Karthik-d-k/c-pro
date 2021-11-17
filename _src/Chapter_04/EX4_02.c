/* Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
   where a floating-point number may be followed by e or E and an optionally signed exponent. */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAXLINE 1000 /* maximum input line length */

double atof(char s[]);

int main()
{
    char s[MAXLINE] = "-123.45e-1";
    double f = 0.0;
    
    f = atof(s);
    printf("String %s converted to float is = %g\n", s, f);
    
    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power, exp;
    int i, sign, exp_sign;
    
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) 
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    exp_sign = (s[i] == '-') ? -1 : 1;  
    if (s[i] == '+' || s[i] == '-')
        i++;    
    for (exp = 0.0; isdigit(s[i]); i++) 
    {
        exp = 10.0 * exp + (s[i] - '0');
    }   
    exp = pow(10.0, (exp_sign * exp));
    
    return ((sign * val / power) *  (exp));
}

/*
ERROR :
-----
$ gcc EX4_02.c
/usr/bin/ld: /tmp/cci7hVKf.o: in function `atof':
EX4_02.c:(.text+0x2fb): undefined reference to `pow'
collect2: error: ld returned 1 exit status

SOLUTION :
--------
The error you are seeing: error: ld returned 1 exit status is from the linker ld (part of gcc that combines the object files) 
because it is unable to find where the function pow is defined.

Including math.h brings in the declaration of the various functions and not their definition. 
The def is present in the math library libm.a. You need to link your program with this library so that the calls to functions like pow() are resolved.

SOURCE :
------
https://stackoverflow.com/a/12824148
*/
