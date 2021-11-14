/* Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. 
   Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. 
   Arrange that a leading or trailing - is taken literally. */

#include <stdio.h>
#include <string.h>
#define LIMIT 200

void expand(char s1[], char s2[]);

int main()
{     
    char s1[LIMIT / 2] = "-a-d0-9A-Da-b-c-d-";
    char s2[LIMIT];
    
    expand(s1, s2);                                                              /* 's2' is modified in-place, by using 's1' as input*/
    printf("converting shorthand notations to equivalent complete list.\n");
    printf("-----------------------------------------------------------\n");
    printf("input  string s1 = '%s'\noutput string s2 = '%s'\n\n", s1, s2);
  
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, k, c;
    
    for (i = 0, j = 0; i < strlen(s1); i++)
    {
        c = s1[i];
        switch(c)
        {
            case '-':
                if (i > 0)
                    for (k = s1[i-1]; k <= s1[i+1]; k++, j++)
                    {
                        if (s2[j-1] == k)
                            j--;    
                        else            
                            s2[j] = k;
                    }
                break;                     
            default:
                break;
        }
    }
    s2[j] = '\0';
}
