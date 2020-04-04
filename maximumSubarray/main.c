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

int crossum(int* nums, int l, int r, int m) {

    int sum = 0, left = INT_MIN;
    for(int i = m ; i >= l ; --i) {
        sum += nums[i];
        left = max(sum, left);
    }


    int right = INT_MIN; sum = 0;
    for(int i = m+1 ; i <= r ; ++i) {
        sum += nums[i];
        right = max(sum, right);
    }

    return left + right;
}

int maxSubArrayRec(int* nums, int l, int r) {
    if(l == r) {
        return nums[l];
    }

    int m = l + ((r - l) >> 1);

    int left = maxSubArrayRec(nums, l, m);
    int right = maxSubArrayRec(nums, m+1, r);
    int cross = crossum(nums, l, r, m);

    return max(max(left, right), cross);
}

int maxSubArrayDC(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }

    return maxSubArrayRec(nums, 0, numsSize - 1);
}

int maxSubArray(int* nums, int numsSize) {
    if(numsSize == 0) {
        return 0;
    }
   
    int b = INT_MIN, c = 0;
    for(int i = 0; i < numsSize; ++i) {
        c = max(nums[i], c + nums[i]);
        b = max(b, c);
    }
    return b;
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

        int res = maxSubArrayDC(nums, n);
        printf("%d\n", res);
    }
    return 0;
}
