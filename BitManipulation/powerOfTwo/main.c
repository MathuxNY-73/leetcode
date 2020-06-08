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

bool isPowerOfTwo(int n){
    if (n < 0) {
        return false;
    }
    return n && !(n & (n - 1));
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        int res = isPowerOfTwo(n);

        printf("%d\n", res);
    }
    return 0;
}
