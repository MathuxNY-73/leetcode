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

#define SIZE 101

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if(numsSize == 0) {
        return nums;
    }

    int* res = malloc(sizeof(int) * numsSize);
    memset(res, 0, sizeof(int) * numsSize);

    res[0] = nums[0];
    for(int i = 1 ; i < numsSize ; ++i) {
        res[i] = res[i - 1] * nums[i];
    }

    int suff_prod = 1;
    for(int i = numsSize - 1 ; i > 0 ; --i) {
        res[i] = res[i - 1] * suff_prod;
        suff_prod *= nums[i];
    }
    res[0] = suff_prod;

    return res;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        int* nums = malloc(sizeof(int) * n);
        memset(nums, 0, sizeof(int) * n);

        int i = 0;
        fl(i, 0, n) {
            fastscan(&nums[i]);
        }

        int returnSize = 0;
        int* res = productExceptSelf(nums, n, &returnSize);

        fl(i, 0, returnSize) {
            printf("%d ", res[i]);
        }
        printf("\n");

        free(res);
        free(nums);
    }
    return 0;
}
