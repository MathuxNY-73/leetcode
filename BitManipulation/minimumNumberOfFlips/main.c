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

#define SIZE 10000

int nb_set_bit(int n) {
    int res = 0;
    while (n) {
        n &= (n - 1);
        ++res;
    }
    return res;
}

int minFlips(int a, int b, int c){
    int res = 0;
    for(int i = 0 ; i < 31 ; ++i) {
        int a_i = a & 1;
        int b_i = b & 1;
        int c_i = c & 1;

        printf("At %d with a_i=%d, b_i=%d and c_i=%d\n", i, a_i, b_i, c_i);
        if (c_i) {
            if (!(a_i | b_i)) {
                printf("Hello 1\n");
                ++res;
            }
        }
        else {
            printf("Hello 2\n");
            res += a_i + b_i;
        }
        printf("Res is %d\n", res);
        a >>= 1; b>>=1; c>>=1;
    }
    return res;
}


int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int a=0, b=0, c=0;
        fastscan(&a);
        fastscan(&b);
        fastscan(&c);

        int res = minFlips(a, b, c);
        printf("%d\n", res);
    }
    return 0;
}
