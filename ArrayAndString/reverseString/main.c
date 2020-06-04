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

void reverseString(char* s, int sSize){
    int start = 0, end = sSize - 1;
    while(start < end) {
        s[start] ^= s[end];
        s[end] ^= s[start];
        s[start++] ^= s[end--];
    }
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        char s[SIZE];
        memset(s, '\0', sizeof(char) * SIZE);

        fastscan_string_w(s, n);

        reverseString(s, n);
        printf("%s\n", s);
    }
    return 0;
}
