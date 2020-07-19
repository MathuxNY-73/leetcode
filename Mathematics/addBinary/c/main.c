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

char * addBinary(char * a, char * b){
    int i = 0, j = 0;

    while(a != NULL && a[i] != '\0') ++i;
    while(b != NULL && b[j] != '\0') ++j;

    char* res = malloc(sizeof(char) * (max(i, j) + 2));
    memset(res, '\0', sizeof(char) * (max(i, j) + 2));

    --i;--j;

    int ptr = 0, carry = 0;
    while(i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) {
            sum += (a[i--] - '0');
        }

        if (j >= 0) {
            sum += (b[j--] - '0');
        }

        res[ptr++] = (char)(sum & 1) + '0';
        carry = sum >> 1;
    }

    if(carry > 0) {
        res[ptr++] = '1';
    }

    int s = 0, e = ptr - 1;
    while(s < e) {
        res[s] ^= res[e];
        res[e] ^= res[s];
        res[s] ^= res[e];
        ++s; --e;
    }

    return res;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, m = 0;
        fastscan(&n);
        fastscan(&m);

        char a[SIZE], b[SIZE];
        memset(a, '\0', sizeof(char)*SIZE);
        memset(b, '\0', sizeof(char)*SIZE);

        fastscan_string_w(a, SIZE);
        fastscan_string_w(b, SIZE);

        char* res = addBinary(a, b);
        printf("%s\n", res);

        free(res);
    }
    return 0;
}
