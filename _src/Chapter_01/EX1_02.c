/* Exercise 1-2. Experiment to find out what happens when prints's argument string contains \c, 
where c is some character not in \n, \t, \b, \". */

#include <stdio.h>

int main()
{
	printf("\a");       /* ‘\a’ is an ASCII BEL character it is a terminal feature it produces a “beep” sound or a notification sound 
	                      simultaneously displaying a terminal or command prompt(windows) */
	return 0;
}
