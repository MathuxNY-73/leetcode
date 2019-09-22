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


int lengthOfLIS(int* nums, int numsSize){
    int* dp = malloc(sizeof(int) * (numsSize + 1));
    memset(dp, 0, sizeof(int) * numsSize);

    for(int i = 0 ; i < numsSize ; ++i) {
        int maxval = 0;

        for(int j = 0 ; j < i ; ++j) {
            if(nums[j] < nums[i]) {
                maxval = max(maxval,dp[j]);
            }
        }

        dp[i] = maxval + 1;
    }

    int res = 0;
    for(int i = 0 ; i < numsSize + 1 ; ++i) {
        if(dp[i] > res) {
            res = dp[i];
        }
    }
    free(dp);
    return res;
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
