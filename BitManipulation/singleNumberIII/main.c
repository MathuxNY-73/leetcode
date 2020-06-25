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

int res[2];

int* singleNumber(int* nums, int numsSize, int* returnSize){

    *returnSize = 2;
    memset(res, 0, sizeof(int) * 2);

    int a = 0;
    for(int i = 0 ; i < numsSize ; ++i) {
        a ^= nums[i];
    }

    int rightmostBit = 1;
    while(!(a & rightmostBit)) {
        rightmostBit <<= 1;
    }

    for(int i = 0 ; i < numsSize ; ++i) {
        if(rightmostBit & nums[i]) {
            res[0] ^= nums[i];
        }
        else {
            res[1] ^= nums[i];
        }
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
        memset(nums, 0, sizeof(int) * n);

        int i = 0;
        fl(i, 0, n) {
            fastscan(&nums[i]);
        }

        int returnSize = 0;
        int* res = singleNumber(nums, n, &returnSize);

        for(int i = 0 ; i < returnSize ; ++i) {
            printf("%d ", res[i]);
        }
        printf("\n");
    }
    return 0;
}
