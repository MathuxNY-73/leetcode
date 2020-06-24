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

#define SIZE 5001

int numTrees(int n){
    if (n == 0) {
        return 0;
    }

    int* dp = malloc(sizeof(int) * (n + 1));
    memset(dp, 0, sizeof(int) * (n + 1));

    dp[0] = 1;
    dp[1] = 1;


    for(int i = 2 ; i <= n ; ++i) {
        for(int j = 0 ; j < i ; ++j) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    int ret = dp[n];
    free(dp);
    return ret;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        int res = numTrees(n);
        printf("%d\n", res);
    }
    return 0;
}
