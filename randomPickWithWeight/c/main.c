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

int cmp(const void* a, const void* b) {
    return *(const int*)a - *(const int*)b;
}

void quicksort(int* array, int size) {
    qsort(array, size, sizeof(int), &cmp);
}

int bin_search(int key, int* array, int size) {
    int lo = 0;
    int hi = size - 1;
    int mid = floor((hi + lo + 1) >> 1);

    while(lo < hi) {
        if(lo == hi + 1 && array[hi] > key) {
            return lo;
        }
        if(array[mid] <= key) {
            lo = mid;
        }
        else if(array[mid] > key) {
            hi = mid - 1;
        }
        mid = floor((hi + lo + 1) >> 1);
    }
    return lo;
}

typedef struct {
    int* m;
    int bound;
    int m_size;
} Solution;


Solution* solutionCreate(int* w, int wSize) {
    Solution* s = malloc(sizeof(Solution));
    s->bound = 0;
    s->m = malloc(sizeof(int)*wSize);
    memset(s->m, -1, sizeof(int)*wSize);

    for(int i = 0 ; i < wSize ; ++i) {
        s->m[i] = s->bound;
        s->bound += w[i];
    }

    s->m_size = wSize;

    srand(time(NULL));

    return s;
}

int solutionPickIndex(Solution* obj) {
    int picked = obj->bound;
    while(picked >= obj->bound) {
        picked = rand() / ((RAND_MAX + 1u) / obj->bound);
    }
    int n_b = bin_search(picked, obj->m, obj->m_size);
    return n_b;
}

void solutionFree(Solution* obj) {
    free(obj->m);
    free(obj);
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int nb_weights = 0;
        fastscan(&nb_weights);
        int* weights= malloc(sizeof(int) * nb_weights);

        int i;
        fl(i, 0, nb_weights){
            fastscan(&weights[i]);
            printf("%d ", weights[i]);
        }
        printf("\n");

        Solution* rand_gen = solutionCreate(weights, nb_weights);

        int nb_pick = 0;
        fastscan(&nb_pick);
        printf("nb_weigths: %d, nb_pick: %d\n", nb_weights, nb_pick);
        wl(nb_pick) {
            int res = solutionPickIndex(rand_gen);
            printf("%d ", res);
        }

        solutionFree(rand_gen);
        free(weights);
        puts("");
    }
    return 0;
}
