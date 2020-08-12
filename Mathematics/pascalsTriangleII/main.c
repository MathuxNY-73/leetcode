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

#define SIZE 50

int* getRow(int rowIndex, int* returnSize){
    int* row = malloc(sizeof(int) * (rowIndex + 1));
    *returnSize = rowIndex + 1;

    memset(row, 0, sizeof(int) * (rowIndex + 1));
    row[0]= 1;

    for(int i = 1 ; i <= rowIndex ; ++i) {
        for(int j = i ; j > 0 ; --j) {
            row[j] += row[j-1];
        }
    }

    return row;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        int returnSize = 0;

        int* res = getRow(n, &returnSize);

        for(int i = 0 ; i < returnSize ; ++i) {
            printf("%d ", res[i]);
        }
        printf("\n");

        free(res);
    }
    return 0;
}
