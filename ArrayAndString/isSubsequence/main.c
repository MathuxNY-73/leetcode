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

bool isSubsequence(char * s, char * t){
    char *ps = s;
    for(char *pt = t; *ps != '\0' && *pt != '\0' ; ++pt) {
        if(*ps == *pt) {
            ++ps;
        }
    }

    return *ps == '\0';
}

int main()
{
    char sw[101], tw[1001];
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, m = 0;
        fastscan(&n);
        fastscan(&m);


        memset(sw, '\0', sizeof(char) * 101);
        memset(tw, '\0', sizeof(char) * 1001);

        fastscan_string_w(sw, n);
        fastscan_string_w(tw, m);

        bool res = isSubsequence(sw, tw);
        printf("%s\n", res ? "True" : "False");
    }
    return 0;
}
