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

#define SIZE 10000

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* res = malloc(sizeof(int) * 2);
    memset(res, 0, sizeof(int) * 2);
    *returnSize = 2;

    if(numsSize == 0) {
        res[0] = res[1] = -1;
        return res;
    }

    int lo = 0, hi = numsSize - 1;
    while(lo < hi) {
        int m1 = lo + (hi - lo) / 3;
        int m2 = hi - (hi - lo) / 3;
        if (target < nums[m1]) {
            hi = m1 - 1;
        }
        else if (target >= nums[m2]) {
            lo = m2;
        }
        else {
            lo = m1;
            hi = m2 - 1;
        }
    }

    if(nums[lo] != target) {
        res[0] = res[1] = -1;
        return res;
    }

    for(int i = lo ;i >= 0 && nums[i] == target ; --i) {
        res[0] = i;
    }

    for(int i = lo; i < numsSize && nums[i] == target ; ++i) {
        res[1] = i;
    }

    return res;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, target = 0;
        fastscan(&n);
        fastscan(&target);

        int* nums = malloc(sizeof(int) * n);
        memset(nums, 0, sizeof(int) * n);

        int i = 0;
        fl(i, 0, n) {
            fastscan(&nums[i]);
        }

        int returnSize = 0;
        int* interval = searchRange(nums, n, target, &returnSize);
        for(i = 0; i < returnSize; ++i) {
            printf("%d ", interval[i]);
        }
        printf("\n");

        free(interval);
        free(nums);

    }
    return 0;
}
