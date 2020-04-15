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

#define SIZE 1001

int singleNumber(int* nums, int numsSize){
    int res = 0;
    for(int i = 0 ; i < numsSize ; ++i) {
        res ^= nums[i];
    }
    return res;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        int nums[SIZE];
        memset(nums, 0, sizeof(int) * SIZE);

        int i = 0;
        fl(i, 0, n) {
            fastscan(&nums[i]);
        }

        int res = singleNumber(nums, n);
        printf("%d\n", res);
    }
    return 0;
}
