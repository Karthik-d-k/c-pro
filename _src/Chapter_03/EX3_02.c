/* Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t 
   as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters. */

#include <stdio.h>
#include <string.h>
#define LIMIT 200

void escape(char s[], char t[]);
void escape_reverse(char s[], char t[]);

int main()
{     
    char s[LIMIT];
    char t[LIMIT / 2] = "a	bc	d	t";
    
    escape(s, t);                                                              /* 's' is modified in-place, by using 't' as input*/
    printf("converting escape characters to visible escape sequences.\n");
    printf("---------------------------------------------------------\n");
    printf("input  string t = '%s'\noutput string s = '%s'\n\n", t, s);
    escape_reverse(s, t);                                                      /* 't' is modified in-place by using modified 's' as input*/
    printf("converting visible escape sequences to real characters.\n");
    printf("---------------------------------------------------------\n");   
    printf("input  string s = '%s'\noutput string t = '%s'\n", s, t);
    
    return 0;
}

void escape(char s[], char t[])
{
    int i, j, c;
    
    for (i = 0, j = 0; i < strlen(t); i++, j++)
    {
        c = t[i];
        switch(c)
        {
            case '\t':
                s[j] = '\\';
                j++;
                s[j] = 't';
                break;
            case '\n':
                s[j] = '\\';  
                j++;
                s[j] = '\n';  
                break;            
            default:
                s[j] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void escape_reverse(char s[], char t[])
{
    int i, j, c;
    
    for (i = 0, j = 0; i < strlen(s); i++, j++)
    {
        c = s[i];
        switch(c)
        {
            case '\\':
                t[j] = ((s[++i] == 't') ? '\t' : ((s[++i] == 'n') ? '\n' : '\\'));
                break;             
            default:
                t[j] = s[i];
                break;
        }
    }
    t[j] = '\0';    
}
