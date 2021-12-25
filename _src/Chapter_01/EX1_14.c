/* Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input. */

#include <stdio.h>

#define LIMIT 100

int main()
{
    int c, i, j, k, u, l, found;
    i = j = k = u = l = found = 0;
    char chars[LIMIT];
    char unique[LIMIT];
    int freqs[LIMIT];

    printf("%s\n", "Enter the input : ");

    while ((c = getchar()) != EOF && i < LIMIT)
    {
        chars[i++] = c;

        for (k = i-1; k >= 0; k--)
        {
            if (chars[i] == chars[k])
            {
                freqs[k] += 1;
                found = 1;
            }
        }
        if (!found)
        {
            unique[u] = chars[i];
            freqs[u] = 1;
            found = 0;
            u++;
        }
        unique[u] = '\0';
    }
    chars[i] = '\0';
    printf("%s %d\n", "unique characters in input : ", u);
    for (l = 0; l < u; l++)
        printf("%d -> %c\n", freqs[l], unique[l]);

    return 0;
}


/* Code is not complete, yet to be completed */
