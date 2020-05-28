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

int* countBits(int num, int* returnSize){
    int* arr = malloc(sizeof(int) * (num + 1));
    memset(arr, 0, sizeof(int) * (num + 1));

    *returnSize = num + 1;

    arr[0] = 0;

    int p2 = 1;
    for(int i = 1 ; i <= num ; ++i) {
        if(i == p2 * 2) {
            p2 *= 2;
        }
        arr[i] = arr[i - p2] + 1;
    }

    return arr;
}

int* countBitsLSB(int num, int* returnSize){
    int* arr = malloc(sizeof(int) * (num + 1));
    memset(arr, 0, sizeof(int) * (num + 1));

    *returnSize = num + 1;

    arr[0] = 0;

    for(int i = 1 ; i <= num ; ++i) {
        arr[i] = arr[i >> 1] + (i & 1);
    }

    return arr;
}

int* countBitsLast(int num, int* returnSize){
    int* arr = malloc(sizeof(int) * (num + 1));
    memset(arr, 0, sizeof(int) * (num + 1));

    *returnSize = num + 1;

    arr[0] = 0;

    for(int i = 1 ; i <= num ; ++i) {
        arr[i] = arr[i & (i - 1)] + 1;
    }

    return arr;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        int returnSize = 0;
        int* res = countBitsLast(n, &returnSize);

        for(int i = 0 ; i < returnSize ; ++i) {
            printf("%d ", res[i]);
        }
        printf("\n");

        free(res);
    }
    return 0;
}
