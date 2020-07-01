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

#define SIZE 1001

int arrangeCoins(int n){
    int res = 0;

    while(n > 0) {
        ++res;
        n -= res;
    }
    return n == 0 ? res : res - 1;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        int res = arrangeCoins(n);
        printf("%d\n", res);
    }
    return 0;
}
