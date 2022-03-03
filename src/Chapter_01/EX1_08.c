/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

int main()
{
    int n_blanks = 0;
    int n_tabs = 0;
    int n_lines = 0; 
    int c;
    
    while((c = getchar()) != EOF)
    {
        if(c == ' ')
            ++n_blanks;
        if(c == '\t')
            ++n_tabs;
        if(c == '\n')
            ++n_lines;      
    }
    
    printf("%s %d\n", "Number of blanks   is =", n_blanks);
    printf("%s %d\n", "Number of tabs     is =", n_tabs);
    printf("%s %d\n", "Number of newlines is =", n_lines);
    
    return 0;
}
