/* Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) 
   Write a version with only one test inside the loop and measure the difference in run-time. */

#include <stdio.h>
#include <time.h>
#define VERSION 2        /* change the version number to either 1 or 2 */
#define CHECK_RUNTIME 1 /* change to 0 to turn off runtime check else for runtime check set value to > 0 */

int binsearch_V01(int x, int v[], int n);
int binsearch_V02(int x, int v[], int n);
double runtime_diff(int x, int v[], int n);

int main()
{     
    int x = 11;
    int n = 11;
    int v[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int found_V01, found_V02;
    
    if (VERSION == 1)
    {
        found_V01 = binsearch_V01(x, v, n);
        if (found_V01 > 0)
            printf("Position of element %d in array v[] is %d (V01)\n", x, found_V01);
        else 
            printf("Element %d not found\n", x);
    }
    else if (VERSION == 2)
    {
        found_V02 = binsearch_V02(x, v, n);
        if (found_V02 > 0)
            printf("Position of element %d in array v[] is %d (V02)\n", x, found_V02);
        else 
            printf("Element %d not found\n", x);
    }
    else
        printf("Entered version number is not correct\n");
    
    if (CHECK_RUNTIME > 0)
    {
        /* runtime difference b/w 2 versions */
        printf("runtime difference b/w V01 and V02 (V01 - V02) ran over 10,000 times is = %f\n", runtime_diff(x, v, n));
    }
    
    return 0;
}

/* binsearch_V01: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch_V01(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    
    while (low <= high) 
    {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else                  /* found match */
            return mid;
    }
    
    return -1;                /* no match */
}

/* binsearch_V02: find x in v[0] <= v[1] <= ... <= v[n-1] :- version with only one test inside the loop */
int binsearch_V02(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    
    while (low <= high) 
    {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else                  
            low = mid + 1;
    }
    if (low >= high)
        return low-1;
    else 
        return -1;       
}

double runtime_diff(int x, int v[], int n)
{
    int average = 10000;
    int i;
    double time_spent1 = 0;
    double time_spent2 = 0;
    
    for (i = 0; i < average; i++)
    {
        clock_t begin1 = clock();
        binsearch_V01(x, v, n);
        clock_t end1 = clock();
        time_spent1 += (double)(end1 - begin1) / CLOCKS_PER_SEC;
        
        clock_t begin2 = clock();
        binsearch_V02(x, v, n);
        clock_t end2 = clock();
        time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
    }
    return (time_spent1 - time_spent2);
}
