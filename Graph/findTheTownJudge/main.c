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

#define SIZE 1001
#define TRUSTSIZE 10000

int findJudge(int N, int trust[TRUSTSIZE][2], int trustSize, int* trustColSize){
    int deg[SIZE];
    memset(deg, 0, sizeof(int) * SIZE);

    for(int i = 0; i < trustSize ; ++i) {
        int t_x = trust[i][0];
        int t_y = trust[i][1];

        --deg[t_x]; ++deg[t_y];
    }

    for(int i = 1 ; i <= N; ++i) {
        if(deg[i] == N - 1) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int t;
    fastscan(&t);

     wl(t)
    {
        int n=0, m = 0;
        fastscan(&n);
        fastscan(&m);

        int trust[TRUSTSIZE][2];
        memset(trust, 0, sizeof(int) * TRUSTSIZE * 2);

        for(int i = 0 ; i < m; ++i) {
            int x = 0, y = 0;
            fastscan(&x);
            fastscan(&y);
            trust[i][0] = x;
            trust[i][1] = y;
        }

        int trustColSize = 2;
        int res = findJudge(n, trust, m, &trustColSize);
       
        printf("%d\n", res);
    }

    return 0;
}
