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

#define SIZE 512

typedef struct {
    int arr[SIZE];
    int size;
    int sum;
    int cnt;
    int tail;
} MovingAverage;

/** Initialize your data structure here. */

MovingAverage* movingAverageCreate(int size) {
    MovingAverage* ma = malloc(sizeof(MovingAverage));
    memset(ma->arr, 0, sizeof(ma->arr));
    ma->size = size;
    ma->tail = ma->sum = ma->cnt = 0;
    return ma;
}

double movingAverageNext(MovingAverage* obj, int val) {
    if(obj->size == 0) {
        return 0;
    }

    if (obj->cnt == obj->size) {
        obj->sum -= obj->arr[obj->tail];
    }
    else {
        ++obj->cnt;
    }
    obj->sum += obj->arr[obj->tail] = val;
    obj->tail = ++obj->tail % obj->size;
    return (double)obj->sum / (double)obj->cnt;
}

void movingAverageFree(MovingAverage* obj) {
    free(obj);
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int w=0, n=0;
        fastscan(&w);
        fastscan(&n);

        MovingAverage* ma = movingAverageCreate(w);

        int i;
        fl(i, 0, n){
            int num = 0;
            fastscan(&num);
            printf("%f\n", movingAverageNext(ma, num));
        }

        movingAverageFree(ma);
    }
    return 0;
}
