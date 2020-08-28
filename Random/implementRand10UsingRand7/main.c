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

int rand7() {
    int picked = 7;
    while(picked >= 7) {
        picked = rand() / ((RAND_MAX + 1u) / 7);
    }
    return picked + 1;
}

int rand10() {
    int picked = 40;
    while(picked >= 40) {
        picked = (rand7() - 1) * 7 + (rand7() - 1);
    }
    return (picked % 10) + 1;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);
        wl(n) {
            int res = rand10();
            printf("%d\n", res);
        }
        puts("");
    }
    return 0;
}
