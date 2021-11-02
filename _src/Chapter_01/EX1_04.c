/* Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table. (°C to °F) */

#include <stdio.h>

#define START 0
#define END 300
#define STEP 20

int main()
{
	int i;
	int temperature;
	
	printf("%s\n", "----------------------------------------");
	printf("Temperature Conversion from C to F\n");
	printf("%s\n", "----------------------------------------");
	printf("%3s\t%6s\n", "C", "F");
	printf("%s\n", "----------------------------------------");
	
	for(i = START; i <= END; i = i + STEP)
	{
		temperature = ((i * 9) + 160) / 5 ;
		printf("%3d\t%6d\n", i, temperature);
	}
	return 0;
}
