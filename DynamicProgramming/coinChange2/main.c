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

int change(int amount, int* coins, int coinsSize){

    int dp[SIZE];
    memset(dp, 0, sizeof(int) * (amount + 1));
    dp[0] = 1;

    for(int i = 0 ; i < coinsSize ; ++i) {
        for(int k = coins[i] ; k <= amount ; ++k) {
            dp[k] += dp[k - coins[i]];
        }
    }

    return dp[amount];
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, m = 0;
        fastscan(&n);
        fastscan(&m);

        int coins[501];
        memset(coins, 0, sizeof(int) * 501);

        for(int i = 0 ; i < m ; ++i) {
            fastscan(&coins[i]);
        }
        int res = change(n, coins, m);
        printf("%d\n", res);
    }
    return 0;
}
