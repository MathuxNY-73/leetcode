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

    int* up = malloc(sizeof(int) * (numsSize + 1));
    int* down = malloc(sizeof(int) * (numsSize + 1));
    memset(up, 0, sizeof(int) * (numsSize + 1));
    memset(down, 0, sizeof(int) * (numsSize + 1));

    up[0] = down[numsSize] = 1;

    for(int i = 0, j = numsSize - 1; i < numsSize && j >= 0 ; ++i, --j) {
        up[i + 1] = up[i] * nums[i];
        down[j] = down[j + 1] * nums[j];
    }

    int* res = malloc(sizeof(int) * numsSize);
    memset(res, 0, sizeof(int) * numsSize);

    for(int i = 0 ; i < numsSize ; ++i) {
        res[i] = up[i] * down[i+1];
    }

    free(up);
    free(down);
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
