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

int perfectSquares(int n) {
    int* dp = malloc(sizeof(int) * (n+1));
    memset(dp, 4, sizeof(int) * (n+1));

    dp[0] = 0;

    for(int i = 1; i <= n ; ++i) {
        for(int j = 1; j*j <= i; ++j) {
            int sq = j * j;
            dp[i] = (int)fmin(dp[i], dp[i - sq] + 1);
        }
    }

    int res = dp[n];
    free(dp);
    return res;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        int res = perfectSquares(n);
        printf("%d\n", res);
    }
    return 0;
}
