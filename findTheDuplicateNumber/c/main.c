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

int findDuplicate(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }

    int tortoise = nums[0];
    int hare = nums[0];
    while(1) {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
        if (hare == tortoise) {
            break;
        }
    }

    int ptr1 = nums[0];
    int ptr2 = tortoise;
    while(ptr1 != ptr2) {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }
    return ptr1;
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

        int res = findDuplicate(nums, n);
        printf("%d\n", res);
        free(nums);
    }
    return 0;
}
