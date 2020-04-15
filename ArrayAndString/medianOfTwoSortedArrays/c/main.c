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

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int* a = nums1Size > nums2Size ? nums1 : nums2;
    int* b = nums1Size > nums2Size ? nums2: nums1;

    int n = nums1Size > nums2Size ? nums1Size: nums2Size;
    int m = nums1Size > nums2Size ? nums2Size: nums1Size;

    int imin = 0, imax = m;

    if(imin == imax) {
        if(n & 1) {
            return a[n / 2];
        }
        else {
            return (a[n / 2] + a[n / 2 - 1]) / 2.0;
        }
    }

    double res = 0;

    while(imin <= imax) {
        int i = imin + (imax - imin) / 2;
        int j = (m + n + 1) / 2  - i;

        if(i < imax && a[j-1] > b[i]) {
            imin = i + 1;
        }
        else if(i > imin && b[i - 1] > a[j]) {
            imax = i - 1;
        }
        else {

            int minRight = 0;
            if(j == n) {
                minRight = b[i];
            }
            else if (i == m) {
                minRight = a[j];
            }
            else {
                minRight = b[i] > a[j] ? a[j] : b[i];
            }

            int maxLeft = 0;
            if(j == 0) {
                maxLeft = b[i - 1];
            }
            else if (i == 0) {
                maxLeft = a[j - 1];
            }
            else {
                maxLeft = b[i - 1] > a[j - 1] ? b[i - 1] : a[j - 1];
            }

            if ((m + n) & 1) {
                res = maxLeft;
            }
            else {
                res = (minRight + maxLeft) / 2.0;
            }
            break;
        }
    }
    return res;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n=0, m = 0;
        fastscan(&n);
        fastscan(&m);
        int* a = malloc(sizeof(int) * n);
        int* b = malloc(sizeof(int) * m);

        int i = 0;
        fl(i, 0, n){
            fastscan(&a[i]);
        }
        fl(i, 0, m) {
            fastscan(&b[i]);
        }


        double res = findMedianSortedArrays(a, n, b, m);
        printf("%f\n", res);
        free(a);
        free(b);
    }
    return 0;
}
