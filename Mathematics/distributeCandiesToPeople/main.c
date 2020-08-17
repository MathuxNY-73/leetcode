#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#include "input.h"

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)
#define min(a,b) (a<=b?a:b)
#define max(a,b) (a>=b?a:b)

#define SIZE 50

int* distributeCandies(int candies, int num_people, int* returnSize){
    int p = floor(sqrt(0.25 + 2.0 * (double)candies) - 0.5);

    int* distri = malloc(sizeof(int) * num_people);
    memset(distri, 0, sizeof(int) * num_people);

    *returnSize = num_people;

    int c = p % num_people;
    int n = p / num_people;

    for(int i = 0; i < num_people ; ++i) {
        distri[i] = n * (i + 1) + num_people * ((n * ( n - 1)) >> 1);
        if (i < c) distri[i] += n * num_people + (i + 1);
        candies -= distri[i];
    }

    distri[c] += candies;

    return distri;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, n_candies = 0;
        fastscan(&n_candies);
        fastscan(&n);

        int returnSize = 0;

        int* res = distributeCandies(n_candies, n, &returnSize);

        for(int i = 0 ; i < returnSize ; ++i) {
            printf("%d ", res[i]);
        }
        printf("\n");

        free(res);
    }
    return 0;
}
