/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2. */

#include <stdio.h>
#define LIMIT 100   /* string length limit */

void get_string(char str[], int max);
void squeeze(char s1[], char s2[]);

int main()
{
	char str1[LIMIT];
	char str2[LIMIT]; 
	
	printf("Enter string 1 and press enter = ");
	get_string(str1, LIMIT);
	printf("Enter string 2 and press enter = ");
	get_string(str2, LIMIT);
	squeeze(str1, str2);
	printf("Squeezed string 1 = %s\n", str1);
	
    return 0;
}

/* squeeze: delete each character in s1 that matches any character in the string s2 */
void squeeze(char s1[], char s2[])
{
	int i, j, k;
	
	for (k = 0; s2[k] != '\0'; k++)
	{
		for (i = j = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] != s2[k])
				s1[j++] = s1[i];
		}
		s1[j] = '\0';
	}
}

/* get_string: read a string into str */
void get_string(char str[], int max)
{
    int i, c;
    
    for (i = 0; i < max-1 && (c = getchar()) != EOF && c != '\n'; i++)
		str[i] = c;
    str[i] = '\0';
}
