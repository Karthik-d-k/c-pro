/* Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables, both signed and
   unsigned, by printing appropriate values from standard headers and by direct computation. 
   Harder if you compute them: determine the ranges of the various floating-point types. */

#include <stdio.h>
#include <limits.h>
#include <float.h>

#define UNSIG_MIN 0  /*minimum value for unsigned datatpes */

int main()
{
    /* initialize all the required variables with the maximum values that it can store by filling in 1's for unsigned and signed(sign bit is set to 0) */
    unsigned char uc = (unsigned char)(~0);
    signed char sc = (unsigned char)(~0) >> 1;
    unsigned short us = (unsigned short)(~0);
    signed short ss = (unsigned short)(~0) >> 1;
    unsigned int ui = (unsigned int)(~0);
    signed int si = (unsigned int)(~0) >> 1;
    unsigned long ul = (unsigned long)(~0);
    signed long sl = (unsigned long)(~0) >> 1;
    
    printf("ranges of char, short, int, and long variables, both signed and unsigned (standard headers)\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("Range of unsigned char is from          : %22d to %22hhu\n", 0, UCHAR_MAX);
    printf("Range of signed char is from            : %22hhi to %22hhi\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of unsigned short int is from     : %22d to %22hu\n", 0, USHRT_MAX);
    printf("Range of signed short int is from       : %22hi to %22hi\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned int is from           : %22d to %22u\n", 0, UINT_MAX);
    printf("Range of signed int is from             : %22i to %22i\n", INT_MIN, INT_MAX); 
    printf("Range of unsigned long int is from      : %22d to %22lu\n", 0, ULONG_MAX);
    printf("Range of signed long int is from        : %22li to %22li\n", LONG_MIN, LONG_MAX);     
    printf("-------------------------------------------------------------------------------------------\n\n");
    
    printf("ranges of char, short, int, and long variables, both signed and unsigned (direct computation)\n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("Range of unsigned char is from          : %22d to %22d\n", UNSIG_MIN, uc);
    printf("Range of signed char is from            : %22hhi to %22hhi\n", -(sc + 1), sc);
    printf("Range of unsigned short int is from     : %22d to %22u\n", UNSIG_MIN, us);
    printf("Range of signed short int is from       : %22hi to %22hi\n", -(ss + 1), ss);
    printf("Range of unsigned int is from           : %22d to %22u\n", UNSIG_MIN, ui);
    printf("Range of signed int is from             : %22i to %22i\n", -(si + 1), si);
    printf("Range of unsigned long int is from      : %22d to %22lu\n", UNSIG_MIN, ul);
    printf("Range of signed long int is from        : %22li to %22li\n", -(sl + 1), sl);
    printf("--------------------------------------------------------------------------------------------\n");   

    return 0;
}
