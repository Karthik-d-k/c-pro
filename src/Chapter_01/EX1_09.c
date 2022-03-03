/* Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */

#include <stdio.h>

int main()
{
    int n_blanks = 0;
    int c;
    
    printf("%s\n", "Enter the input string ");
    while((c = getchar()) != EOF)
    {
        if(c != ' ')
        {
            if(n_blanks > 1)
                putchar(' ');
            putchar(c);
            n_blanks = 0;
        }
        else
        {
            ++n_blanks;
        }
    }

    return 0;
}
