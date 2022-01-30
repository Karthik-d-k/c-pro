/* Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text. */

#include <stdio.h>
#define MAXlines 500   /* maximum input lines length */
#define MAXLENGTH 50 /* maximum possible text characters to print */

int lineslength(char lines[]);

/* print the arbitrary input lines */
int main()
{
    int len; /* length of an input */
    char lines[MAXlines]; /* input liness */
    int l;
    
    len = lineslength(lines);                           /*by passing lines -> we are calling by reference i.e, pointing to the 0th index address of an array by specifying array name */
    printf("%s %d\n", "length of an input", len);

    for (l = 0; l < MAXLENGTH; ++l)
        putchar(lines[l]);
        
    return 0;
}

/* getlines: read a lines into s, return length */
int lineslength(char s[])
{
    int c, i;
    
    for (i=0; (c=getchar()) != EOF; ++i)
    {
        if (c == '\n')
        {
            s[i] = '.';
            ++i;
        }
        else
            s[i] = c;
    }
    s[i] = '\0';
    
    return i;
}
