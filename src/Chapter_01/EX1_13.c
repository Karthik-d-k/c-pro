/* Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. 
   It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#include <stdio.h>

int main()
{
    int c, len;
    len = 0;
    
    printf("%s\n", "Enter the input : ");
    
    while ((c = getchar()) != EOF) 
    {
        if (!((c == ' ') || (c == '\n') || (c == '\t')))
        {
            ++len;
            printf("*");
        }
        else 
        {
            len = 0;
            printf("\n");
        }
    }
    
    return 0;
}
