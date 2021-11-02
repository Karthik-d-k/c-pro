/* Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.*/

#include <stdio.h>

#define START 0
#define END 300
#define STEP 20

int fah_to_cel(int fah);

int main()
{
	int i;
	int temperature;
	
	printf("%s\n", "----------------------------------------");
	printf("Temperature Conversion from F to C\n");
	printf("%s\n", "----------------------------------------");
	printf("%3s\t%6s\n", "F", "C");
	printf("%s\n", "----------------------------------------");
	
	for(i = START; i <= END; i = i + STEP)
	{
		temperature = fah_to_cel(i);
		printf("%3d\t%6d\n", i, temperature);
	}
	return 0;
}

int fah_to_cel(int fah)
{
	return (5 * (fah - 32) / 9);
}
