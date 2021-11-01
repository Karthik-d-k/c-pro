/* Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input. */

#include <stdio.h>

int main()
{
	int c, i, j, k, l, c1, c2, len;
	i = j = k = l = 0;
	len = 1;
	char chars[500];
	char unique[500];
	int lens[500];
	
	printf("%s\n", "Enter the input : ");
	
	while ((c = getchar()) != EOF)
	{
		chars[i] = c;
		++i;
	}
	chars[i] = '\0';
	
	unique[0] = chars[0];
	for (j = 1; j <= i; j++)
	{
		for (k = j-1; k == 1; k--)
		{
			if (chars[j] != chars[k])
			{
				unique[len] = chars[j];
				++len;
				break;
			}
		}
	}
	unique[len] = '\0';
	
	printf("%s\n", "unique characters in input : ");
	printf("%d\n",  len);
	for (l = 0; l < len; l++)
		putchar(unique[l]);
	
	return 0;
}


/* Not a complete code -> yet to be completed */