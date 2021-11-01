/* Exercise 1-3. Create the temperature conversion program (°F to °C) to print a heading above the table.*/

#include <stdio.h>

#define START 0
#define END 300
#define STEP 20

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
		temperature = 5 * (i - 32) / 9;
		printf("%3d\t%6d\n", i, temperature);
	}
	return 0;
}
