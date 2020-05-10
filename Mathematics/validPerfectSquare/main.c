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

bool isPerfectSquare(int num){
    if (num < 2) {
        return true;
    }

    int x = num >> 1;
    while (x > (INT_MAX / x) || x * x > num) {
        x = (x + num / x) >> 1;
    }
    return x * x == num;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        bool res = isPerfectSquare(n);
        printf("%s\n", res ? "true": "false");
    }
    return 0;
}
