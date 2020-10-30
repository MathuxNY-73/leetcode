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

bool kmp(char* str, int n, char* pattern, int m) {

    int* shift = (int*)malloc(m * sizeof(int));
    for(int i = 0 ; i < m ; ++i) shift[i] = -1;

    for(int i = 1, j = 0 ; i < m ;) {
        if(pattern[i] == pattern[j]) shift[i++] = j++;
        else if(j > 0) j = shift[j - 1] + 1;
        else ++i;
    }

    int j = 0;
    for(int i = 0 ; i < n && j < m ;) {
        if(str[i] == pattern[j]) {++j; ++i;}
        else if(j > 0) j = shift[j - 1] + 1;
        else ++i;
    }

    free(shift);
    return j == m;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, m = 0;
        fastscan(&n);
        fastscan(&m);

        char* str = (char*)malloc((n + 1) * sizeof(char));
        memset(str, '\0', sizeof(char) * (n +1 ));
        char* pattern = (char*)malloc((m + 1) * sizeof(char));
        memset(pattern, '\0', sizeof(char) * (m +1 ));

        //fread(str, sizeof(char), n, stdin);
        //fgetc(stdin);
        //fread(pattern, sizeof(char), m, stdin);
        //fgetc(stdin);

        fastscan_string(str, n);
        fastscan_string(pattern, m);

        bool res = kmp(str, n, pattern, m);
        printf("%s\n", res ? "True" : "False");

        free(str);
        free(pattern);
    }
    return 0;
}
