#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#include "input.h"

#define min(a,b) a<=b?a:b

void reverse(int* nums, int l, int r) {
    while(l < r) {
       nums[l] ^= nums[r];
       nums[r] ^= nums[l];
       nums[l] ^= nums[r];
       ++l; --r;
    }
}

void rotate(int* nums, int numsSize, int k){
    if(numsSize == 0) return;

    int mov = k % numsSize;

    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, mov - 1);
    reverse(nums, mov, numsSize - 1);
}

int main()
{
    int t;
    fastscan(&t);

    while(t--) {
        int n=0, k = 0;
        fastscan(&n);
        fastscan(&k);
        int* array = malloc(sizeof(int) * n);

        for(int i = 0 ; i < n ; ++i){
            fastscan(&array[i]);
        }

        rotate(array, n, k);

        for(int i = 0 ; i < n ; ++i) {
            printf("%d ", array[i]);
        }
        printf("\n");
        free(array);
        puts("");
    }
    return 0;
}
