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

#define SIZE 201

int get_size(char* s) {
    int res = 0;
    while(s[res] != '\0') {
        ++res;
    }
    return res;
}

bool backspaceCompare(char * S, char * T){
    int i = get_size(S) - 1, j = get_size(T) - 1;

    while(i >= 0 || j >= 0) {
        int skip = 0;
        while (i>=0) {
            if(S[i] == '#') {++skip; --i;}
            else if (skip > 0) {--skip; --i;}
            else {break;}
        }

        skip = 0;
        while (j >= 0) {
            if(T[j] == '#') {++skip; --j;}
            else if (skip > 0) {--skip; --j;}
            else {break;}
        }

        if(i >= 0 && j >= 0 && S[i] != T[j]) {
            return false;
        }

        if ((i >= 0) ^ (j >= 0)) {
            return false;
        }
        --i;--j;
    }
    return true;
}

int main()
{
    int t;
    fastscan(&t);

    char S[SIZE];
    char T[SIZE];

    wl(t) {
        int n = 0, m = 0;
        fastscan(&n);
        fastscan(&m);

        memset(S, '\0', sizeof(char) * SIZE);
        memset(T, '\0', sizeof(char) * SIZE);

        fastscan_string_w(S, n);
        fastscan_string_w(T, m);
       
        bool res = backspaceCompare(S, T);
        printf("%s\n", res ? "true" : "false");
    }
    return 0;
}
