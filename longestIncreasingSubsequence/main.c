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
#define min(a,b) a<=b?a:b

int lengthOfLIS(int* nums, int numsSize){
    int max_lis = 1;

    for(int i = 0 ; i < numsSize ; ++i) {
        int j = i, lis = 1;
        while(j < numsSize - 1 && nums[j] < nums[j+1]) {
            ++lis;
            ++j;
        }

        if(lis > max_lis) {
            max_lis = lis;
        }
        i = j;
    }

    return max_lis;
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
