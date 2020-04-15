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

int* pancakeSort(int* A, int ASize, int* returnSize) {
    *returnSize = 0;
    int* res = malloc(sizeof(int) * 2*ASize);
    memset(res, 0, sizeof(int) * 2 * ASize);
    int idx = 0;
    for(int i = ASize - 1 ; i >= 0 ; --i) {
        int max = 0, imax = -1;
        for(int j = 0 ; j <= i ; ++j) {
            if(A[j] > max) {
                max = A[j];
                imax = j;
            }
        }

        if(imax != - 1 && imax != i) {
            //printf("imax: %d \n", imax);
            for(int k = 0 ; k <= imax / 2 ; ++k) {
                int tmp = A[k];
                A[k] = A[imax - k];
                A[imax-k] = tmp;
            }

            for(int k = 0 ; k <= i / 2 ; ++k) {
                int tmp = A[k];
                A[k] = A[i - k];
                A[i-k] = tmp;
            }

            res[idx++] = imax +1;
            res[idx++] = i + 1;
            *returnSize += 2;

            //printf("return Size: %d\n", *returnSize);
            //for(int l = 0 ; l < ASize ; ++l) {
            //    printf("%d ", A[l]);
            //}
            //printf("\n");

        }
    }
    return res;
}

int main()
{
    int t;
    fastscan(&t);

    while(t--) {
        int n=0;
        fastscan(&n);
        int* A = malloc(sizeof(int) * n);

        for(int i = 0 ; i < n ; ++i){
            fastscan(&A[i]);
        }


        int returnSize = 0;
        int* res = pancakeSort(A, n, &returnSize);

        for(int i = 0 ; i < returnSize ; ++i) {
            printf("%d ", res[i]);
        }
        printf("\n");
        free(res);
        free(A);
        puts("");
    }
    return 0;
}
