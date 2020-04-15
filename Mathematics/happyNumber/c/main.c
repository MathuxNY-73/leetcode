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

int getNext(int num) {
    int res = 0;
    while(num) {
        div_t d = div(num, 10);
        res += d.rem * d.rem;
        num = d.quot;
    }

    return res;
}

bool isHappy(int num){
    int tortoise = num;
    int hare = getNext(num);
    while(hare != tortoise) {
        tortoise = getNext(tortoise);
        hare = getNext(getNext(hare));
    }
    return tortoise == 1;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        bool res = isHappy(n);
        printf("%s\n", res ? "true": "false");
    }
    return 0;
}
