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

int binSearch(const int* a, int s, int el, bool* found) {
    int l = 0, r = s - 1;
    int m = (l+r) / 2;
    *found = false;

    while(l <= r) {

        if(el == a[m]) {
            *found = true;
            return m;
        }
        else if(el < a[m]) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }

        m = (l+r) / 2;
    }

    return l;
}

int lengthOfLIS(int* nums, int numsSize){
    int* dp = malloc(sizeof(int) * (numsSize));
    memset(dp, 0, sizeof(int) * numsSize);
    int dp_size = 0;

    for(int i = 0 ; i < numsSize ; ++i) {
        bool found;
        int idx = binSearch(dp, dp_size, nums[i], &found);
        if(idx == dp_size) {
            dp[dp_size++] = nums[i];
        }
        else if (!found) {
            dp[idx] = nums[i];
        }
    }

    free(dp);
    return dp_size;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n=0;
        fastscan(&n);
        int* nums = malloc(sizeof(int) * n);

        int i;
        fl(i, 0, n){
            fastscan(&nums[i]);
        }

        int res = lengthOfLIS(nums, n);
        printf("%d\n", res);
        free(nums);
    }
    return 0;
}
