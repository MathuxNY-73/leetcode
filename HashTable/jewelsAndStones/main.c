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

#define SIZE 51

int numJewelsInStones(char * J, char * S){
    bool jewels[52];
    memset(jewels, false, sizeof(bool) * 52);

    for(int i = 0; J[i] != '\0' && i < 52 ; ++i) {
        int upper_idx = J[i] - 'A';
        int idx = upper_idx >= 26 ? J[i] - 'a' + 26 : upper_idx;
        jewels[idx] = true;
    }

    int res = 0;
    for(int i = 0; S[i] != '\0'; ++i) {
        int upper_idx = S[i] - 'A';
        int idx = upper_idx >= 26 ? S[i] - 'a' + 26 : upper_idx;
        res += (int)(jewels[idx]);
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

        char J[SIZE], S[SIZE];
        memset(J, '\0', sizeof(char) * SIZE);
        memset(S, '\0', sizeof(char) * SIZE);

        fastscan_string_w(J, SIZE);
        fastscan_string_w(S, SIZE);

        int res = numJewelsInStones(J, S);
        printf("%d\n", res);
    }
    return 0;
}
