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

int mincostTickets(int* days, int daysSize, int* costs, int costsSize){
    if (daysSize == 0) return 0;

    int dp[366], durations[3] = {1,7,30};

    for(int i = 0; i < 366 ; ++i) dp[i] = INT_MAX;

    dp[0] = 0;

    int ptr = 0;
    int i = 1;
    for(; i <= days[daysSize - 1] ; ++i) {
        if(days[ptr] == i) {
            for(int k = 0 ; k < 3 ; ++k) {
                dp[i] = min(dp[i], dp[max(0, i - durations[k])] + costs[k]);
            }
            ++ptr;
        }
        else {
            dp[i] = dp[i - 1];
        }
    }
    return dp[i - 1];
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        int days[365], costs[3];
        memset(days, 0, sizeof(int) * 365);
        memset(costs, 0, sizeof(int) * 3);

        for(int i = 0 ; i < n ; ++i) {
            fastscan(&days[i]);
        }
        for(int i = 0 ; i < 3 ; ++i) {
            fastscan(&costs[i]);
        }
        int res = mincostTickets(days, n, costs, 3);
        printf("%d\n", res);
    }
    return 0;
}
