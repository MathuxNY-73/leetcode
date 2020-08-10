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

#define SIZE 50

int titleToNumber(char * s){
    int res = 0;
    int i = 0;
    while(s[i] != '\0') {
        res *= 26;
        res += (int)(s[i++] - 'A') + 1;
    }

    return res;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        char col[SIZE];
        memset(col, '\0', sizeof(char) * SIZE);

        fastscan_string_w(col, n);

        int res = titleToNumber(col);
        printf("%d\n", res);
    }
    return 0;
}
