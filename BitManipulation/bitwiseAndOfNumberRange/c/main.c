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

int rangeBitwiseAndBad(int m, int n){
    if (m == 0) {
        return 0;
    }

    int r = m, p = 1, cnt = 1;
    while(r && cnt < 31) {
        r >>=1;
        p <<=1;
        ++cnt;
    }

    printf("For m=%d p=%d\n", m , p);
    if(cnt <= 31 && (m < p && n >= p)) {
        return 0;
    }
    else {
        // Corner case where m >= 0x40000000
        p = m >= p ? p : p >> 1;
        int res = p;
        p >>= 1;
        while((n & p) == (m & p) && p) {
            res += (n&p);
            p >>=1;
        }
        return res;
    }
    return 0;
}

int rangeBitwiseAnd(int m, int n){
    int shift = 0;
    while(m < n) {
        m >>=1;
        n >>=1;

        ++shift;
    }
    return m << shift;
}

int rangeBitwiseAndOpt(int m, int n){
    while(m < n) {
        n = n & (n - 1);
    }
    return n & m;
}


int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int m = 0, n = 0;
        fastscan(&m);
        fastscan(&n);

        int res = rangeBitwiseAnd(m, n);
        printf("%d\n", res);
    }
    return 0;
}
