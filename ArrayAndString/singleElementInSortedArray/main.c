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

int singleNonDuplicate(int* nums, int numsSize) {
    int lo = 0, hi = numsSize;
    while (lo < hi) {
        int m = lo + ((hi - lo) >> 1);
        if (m & 1) {
            if (m > 0 && nums[m] == nums[m - 1]) {
                lo = m + 1;
            }
            else if (m < numsSize - 1 && nums[m] == nums[m + 1]) {
                hi = m - 1;
            }
            else {
                return nums[m];
            }
        }
        else {
            if (m > 0 && nums[m] == nums[m - 1]) {
                hi = m;
            }
            else if (m < numsSize - 1 && nums[m] == nums[m + 1]) {
                lo = m;
            }
            else {
                return nums[m];
            }
        }
    }

    return nums[lo];
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

        for(int i = 0 ; i < n ; ++i) {
            fastscan(&nums[i]);
        }

        int res = singleNonDuplicate(nums, n);
        printf("%d\n", res);
    }
    return 0;
}
