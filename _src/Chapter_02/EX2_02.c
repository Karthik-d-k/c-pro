/* Exercise 2-2. Write a loop equivalent to the for loop (my_getline_V01) below without using && or || (my_getline_V02). */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define VERSION 2    /* change the version number to either 0 or 1 */

int getline_V01(char line1[], int maxline1);
int getline_V02(char line2[], int maxline2);

/* print the input line length */
int main()
{
    int len_V01, len_V02;      /* line length */
    len_V01 = len_V02 = 0;
    char line[MAXLINE];        /* current input line */
    
    if (VERSION == 1)
    {
        len_V01 = getline_V01(line, MAXLINE);
        printf("Line length by V01 : %d\n", len_V01);
    }
    else if (VERSION == 2)
    {
        len_V02 = getline_V02(line, MAXLINE); 
        printf("Line length by V02 : %d\n", len_V02);
    }
    else
        printf("Entered version number is not correct\n");
    
    return 0;
}

/* getline_V01: read a line into s, return length */
int getline_V01(char s1[],int lim1)
{
    int c1, i1;
    
    for (i1=0; i1 < lim1-1 && (c1=getchar())!=EOF && c1!='\n'; i1++)
    s1[i1] = c1;
    if (c1 == '\n')
    {
        s1[i1] = c1;
        ++i1;
    }
    s1[i1] = '\0';
    
    return i1;
}

/* getline_V02: read a line into s, return length without using && or || */
int getline_V02(char s2[],int lim2)
{
    int c2, i2;
    
    for (i2=0; i2 < lim2-1; i2++)
    {
        if((c2 = getchar()) != EOF)
            if(c2 != '\n')
                s2[i2] = c2;    
            else 
                break;
        else 
            break;
    }
    
    if(c2 == '\n')
    {
        s2[i2] = c2;
        ++i2;
    }
    s2[i2] = '\0';
    
    return i2;
}
