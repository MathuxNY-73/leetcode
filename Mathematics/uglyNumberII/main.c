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

#define SIZE 2000

int nthUglyNumber(int n){
    int dp[SIZE];

    memset(dp, 0, sizeof(int) * SIZE);
    dp[0] = 1;

    int i2 = 0, i3 = 0, i5 = 0;
    for(int i = 1 ; i < n ; ++i) {
        dp[i] = min(dp[i2] * 2, min(dp[i3] * 3, dp[i5] * 5));
        if(dp[i2] * 2 == dp[i]) ++i2;
        if(dp[i3] * 3 == dp[i]) ++i3;
        if(dp[i5] * 5 == dp[i]) ++i5;
    }

    return dp[n - 1];
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        int res = nthUglyNumber(n);
        printf("%d\n", res);
    }
    return 0;
}
