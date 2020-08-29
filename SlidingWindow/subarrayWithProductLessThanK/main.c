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

int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if(numsSize <= 1) {
        return 0;
    }

    int l = 0, r = 0;
    int prod = 1, cnt = 0;
    while(l <= r && r < numsSize) {
        prod *= nums[r];
        while(l < r && prod >= k) prod /= nums[l++];

        if(prod < k) cnt += (r - l) + 1;
        ++r;
    }
    return cnt;
}


int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, k = 0;
        fastscan(&n);
        fastscan(&k);

        int* nums = malloc(sizeof(int) * n);
        memset(nums, 0, sizeof(int) * n);

        for(int i = 0 ; i < n ; ++i) fastscan(nums + i);

        int res = numSubarrayProductLessThanK(nums, n, k);
        printf("%d\n", res);
    }
    return 0;
}
