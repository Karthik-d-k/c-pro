/* Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs, 
   or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.) */

#include <stdio.h>
#define LIMIT 100   /* string length limit */

void get_string(char str[], int max);
int any(char s1[], char s2[]);

int main()
{
    char str1[LIMIT];
    char str2[LIMIT]; 
    int value = -1;
    
    printf("Enter string 1 and press enter = ");
    get_string(str1, LIMIT);
    printf("Enter string 2 and press enter = ");
    get_string(str2, LIMIT);
    value = any(str1, str2);
    if (value != -1)
        printf("First location in string 1 is = %d, character = %c\n", value, str1[value]);
    else
        printf("No match found, value = %d\n", value);
    
    return 0;
}

/* any: returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2 */
int any(char s1[], char s2[])
{
    int i, j;
    
    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
                return i;
        }
    }   
    
    return -1;
}

/* get_string: read a string into str */
void get_string(char str[], int max)
{
    int i, c;
    
    for (i = 0; i < max-1 && (c = getchar()) != EOF && c != '\n'; i++)
        str[i] = c;
    str[i] = '\0';
}
