/* Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1. */

#include <stdio.h>

int main()
{
    int c;
    
    c = (getchar() != EOF);
    printf("%s", "The value of the expression 'getchar() != EOF' is = ");
    printf("%d", c);
    
    return 0;
}
/* Exercise 1-7. Write a program to print the value of EOF. */

#include <stdio.h>

int main()
{
    printf("%s %d", "The value of the 'EOF' is =", EOF);
    
    return 0;
}
