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

#define SIZE 10000

void merge_with_space(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int* nums1_copy = malloc(sizeof(int) * m);
    memset(nums1_copy, m, sizeof(int) * m);

    for (int i = 0 ; i < m ; ++i) {
        nums1_copy[i] = nums1[i];
    }

    int i = 0, j = 0;
    while(i < m && j < n) {
        if(nums1_copy[i] <= nums2[j]) {
            nums1[i+j] = nums1_copy[i];
            ++i;
        }
        else {
            nums1[i+j] = nums2[j];
            ++j;
        }
    }

    while(i < m) {
        nums1[n+i] = nums1_copy[i];
        ++i;
    }

    while(j < n) {
        nums1[m+j] = nums2[j];
        ++j;
    }

    free(nums1_copy);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m - 1, j = n - 1;
    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j]) {
            nums1[i+j+1] = nums1[i];
            --i;
        }
        else {
            nums1[i+j+1] = nums2[j];
            --j;
        }
    }

    while(j >= 0) {
        nums1[j] = nums2[j];
        --j;
    }
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, m = 0;
        fastscan(&m);
        fastscan(&n);

        int* nums1 = malloc(sizeof(int) * (m+n));
        int* nums2 = malloc(sizeof(int) * n);
        memset(nums1, 0, sizeof(int) * (m+n));
        memset(nums2, 0, sizeof(int) * n);

        for(int i = 0 ; i < m ; ++i) {
            fastscan(&nums1[i]);
        }
        for(int i = 0 ; i < n ; ++i) {
            fastscan(&nums2[i]);
        }

        merge(nums1, m, m, nums2, n, n);
        for(int i = 0 ; i < n+m ; ++i) {
            printf("%d ", nums1[i]);
        }
        printf("\n");

        free(nums1);
        free(nums2);
    }
    return 0;
}
