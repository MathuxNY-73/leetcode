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

bool isPowerOfFour(int num){

    if (num <= 0) {
        return false;
    }
    while (num % 4 == 0) {
        num >>= 2;
    }
    return num == 1;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        bool res = isPowerOfFour(n);
        printf("%s\n", res ? "True" : "False");
    }
    return 0;
}
