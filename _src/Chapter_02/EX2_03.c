/* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. 
   The allowable digits are 0 through 9, a through f, and A through F. */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define LIMIT 8     /* Maximum no. of Hexadecimal bits */

int get_hex(char line[], int lim);
unsigned long int hex2int(char s[], int length);
unsigned long int char2int(char c);

int main()
{
	int len = 0;
	unsigned long int integer = 0;
	char inp[LIMIT + 2];
	
	printf("Enter the hexadecimal no (Max allowed no. of bits is %d):\n", LIMIT);
	len = get_hex(inp, (LIMIT + 2));
	integer = hex2int(inp, len);
	printf("\nHexadecimal number (Input): %s\nEquivalent integer number (Output): %lu\n", inp, integer);
    
    return 0;
}

/* getline: read a line (LOWERCASE) into s, return length */
int get_hex(char s[],int lim)
{
    int c, i;
    
    for (i = 0; i < lim && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = toupper(c);
    s[i] = '\0';
    
    return i;
}

/* hex2int: read array containing heaxadecimal no. and return decimal integer value. */
unsigned long int hex2int(char s[], int length)
{
	int bit_pos;
	unsigned long int a = 0;
	bool cond = false;
	cond = (s[0] == '0' && s[1] == 'X');
	
	for (bit_pos = (length-1); (bit_pos >= (cond ? 2 : 0)); --bit_pos)      /* cond is used to exclude 0X prefix if present in the input*/
		a += (char2int(s[bit_pos])) << (4 * (length -1 - bit_pos));

	return a;
}

/* convert given character back to its integer form */
unsigned long int char2int(char c)
{
	unsigned long int i = 0;
	
	if (c >= '0' && c <= '9')
		i = (unsigned long int) (c - '0');
	else
	{
		switch(c)
		{

			case 'A':
				i = 10;
				break;
			case 'B':
				i = 11;
				break;
			case 'C':
				i = 12;
				break;
			case 'D':
				i = 13;
				break;
			case 'E':
				i = 14;
				break;
			case 'F':
				i = 15;
				break;
			default:
				i = 0;
		}	
	}
	
	return i;
}
