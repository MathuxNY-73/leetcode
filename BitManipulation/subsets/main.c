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

#define MAX 0x7FFFFFFF

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    unsigned int bound = 1 << numsSize;
    *returnSize = (int)bound;

    int* buf = malloc(sizeof(int) * numsSize);
    memset(buf, 0, sizeof(int) * numsSize);

    int** res = malloc(sizeof(int*) * (1 << numsSize));

    *returnColumnSizes = malloc(sizeof(int) * (1 << numsSize));
    memset(*returnColumnSizes, 0, sizeof(int) * (1 << numsSize));

    for(unsigned int i = 0 ; i < bound ; ++i) {
        unsigned int tmp = i, cnt = 0, idx = 0;

        while(tmp) {
            if(tmp & 1) buf[cnt++] = nums[idx];
            ++idx;
            tmp >>= 1;
        }

        (*returnColumnSizes)[i] = cnt;

        res[i] = malloc(sizeof(int) * cnt);
        memset(res[i], 0, sizeof(int) * cnt);

        for(unsigned int k = 0; k < cnt; ++k) {
            res[i][k] = buf[k];
        }
    }
    free(buf);

    return res;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        int* nums = malloc(sizeof(int)*n);

        for(int i = 0 ; i < n ; ++i) {
            fastscan(&nums[i]);
        }

        int* returnColumnSizes;
        int returnSize;

        int** res = subsets(nums, n, &returnSize, &returnColumnSizes);

        for(int i = 0 ; i < returnSize ; ++i) {
            printf("[");
            for(int j = 0 ; j < returnColumnSizes[i] ; ++j) {
                printf("%d ", res[i][j]);
            }
            printf("]\n");
            free(res[i]);
        }

        free(res);
        free(returnColumnSizes);
    }
    return 0;
}
