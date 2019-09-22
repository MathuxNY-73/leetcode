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


typedef struct Num {
    int val;
    int idx;
} Num;

int cmp_num(const void* l, const void* r) {
    return (((Num*)l)->val - ((Num*)r)->val);
}

int lengthOfLIS(int* nums, int numsSize){
    if(numsSize == 0) {
        return 0;
    }

    bool* inSeq = malloc(sizeof(bool) * numsSize);
    memset(inSeq, 0 , sizeof(bool) * numsSize);
    Num* numsIdx = malloc(sizeof(Num) * numsSize);
    memset(numsIdx, 0, sizeof(Num)*numsSize);

    int max_lis = 1;

    for(int i = 0 ; i < numsSize ; ++i) {
        numsIdx[i].val = nums[i];
        numsIdx[i].idx = i;
    }

    qsort(numsIdx, numsSize, sizeof(Num), &cmp_num);

    for(int i = 0 ; i < numsSize && max_lis <= (numsSize / 2) ; ++i) {
        if(!inSeq[i]) {
            Num prev = numsIdx[i];
            int lis = 1;
            inSeq[i] = true;
            for(int j = i + 1 ; j < numsSize ; ++j) {
                if(numsIdx[j].val > prev.val && numsIdx[j].idx > prev.idx) {
                    ++lis;
                    prev = numsIdx[j];
                    inSeq[j] = true;
                }
            }

            if(lis > max_lis) {
                max_lis = lis;
            }
        }
    }
    free(numsIdx);
    free(inSeq);

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
