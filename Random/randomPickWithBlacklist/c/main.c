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

void heapify(int* array, int size, int i) {
    int l = 2 * i + 1;
    int r = 2*(i + 1);
    int largest = i;
    if(l < size && array[l] > array[i]) {
        largest = l;
    }

    if(r < size && array[r] > array[largest]) {
        largest = r;
    }

    if(largest != i) {
        array[i] ^= array[largest];
        array[largest] ^= array[i];
        array[i] ^= array[largest];
        heapify(array, size, largest);
    }
}

void build_heap(int* array, int size) {
    for(int i = (size / 2) - 1 ; i >= 0 ; --i) {
        heapify(array, size, i);
    }
}

void heap_sort(int* array, int size) {
    build_heap(array, size);
    for(int i = 1 ; i < size ; ++i) {
        array[0] ^= array[size-i];
        array[size-i] ^= array[0];
        array[0] ^= array[size-i];
        heapify(array, size - i , 0);
    }
}

int bin_search(int key, int* array, int size) {
    int lo = 0;
    int hi = size - 1;
    int mid = floor((hi + lo + 1) / 2);

    while(lo < hi) {
        int c = array[mid] - mid;
        if(c <= key) {
            lo = mid;
        }
        else if(c > key) {
            hi = mid - 1;
        }
        mid = floor((hi + lo + 1) / 2);
    }
    return lo == hi && array[lo] - lo <= key ? key + lo + 1 : key;
}

typedef struct {
    int* b;
    int bound;
    int b_size;
} Solution;


Solution* solutionCreate(int N, int* blacklist, int blacklistSize) {
    Solution* s = malloc(sizeof(Solution));
    heap_sort(blacklist, blacklistSize);
    s->b = blacklist;
    s->bound = N - blacklistSize;
    s->b_size = blacklistSize;

    srand(time(NULL));

    return s;
}

int solutionPick(Solution* obj) {
    int picked = obj->bound;
    while(picked >= obj->bound) {
        picked = rand() / ((RAND_MAX + 1u) / obj->bound);
    }
    int n_b = bin_search(picked, obj->b, obj->b_size);
    return n_b;
}

void solutionFree(Solution* obj) {
    free(obj);
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n=0;
        fastscan(&n);
        int nb_blacklist = 0;
        fastscan(&nb_blacklist);
        int* blacklist = malloc(sizeof(int) * nb_blacklist);

        int i;
        fl(i, 0, nb_blacklist){
            fastscan(&blacklist[i]);
        }

        Solution* rand_gen = solutionCreate(n, blacklist, nb_blacklist);

        int nb_pick = 0;
        fastscan(&nb_pick);

        int test[7] = {3,2,6,5,9,1,4};
        heap_sort(&test, 7);
        for(int i = 0 ; i < 7 ; ++i) {
            printf("%d ", test[i]);
        }
        printf("\n");
        printf("2: %d\n", bin_search(2, blacklist, nb_blacklist));
        printf("1: %d\n", bin_search(1, blacklist, nb_blacklist));

        printf("N = %d, nb_blacklist: %d, nb_pick: %d\n", n, nb_blacklist, nb_pick);
        wl(nb_pick) {
            int res = solutionPick(rand_gen);
            printf("%d ", res);
        }

        solutionFree(rand_gen);
        free(blacklist);
        puts("");
    }
    return 0;
}
