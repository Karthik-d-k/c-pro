/* Exercise 1-12. Write a program that prints its input one word per line. */

#include <stdio.h>

int main()
{
	int c, nw;
	nw = 0;
	
	printf("%s\n", "Enter the input : ");
	printf("%s\n", "----------------------------");
	
	while ((c = getchar()) != EOF) 
	{
		if (!((c == ' ') || (c == '\n') || (c == '\t')))
			putchar(c);
		else 
		{
			putchar('\n');									/* use single quotes instead of double quotes to avoid -> warning : passing arg 1 of `putchar' makes integer from pointer without a cast. */
			++nw;											/* just to count no. of words. */
		}
	}
	
	printf("%s\n", "----------------------------");
	printf("%s %d\n", "No of words present in the input : ", nw);
	
	return 0;
}
