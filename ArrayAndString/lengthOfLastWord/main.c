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

int lengthOfLastWord(char * s) {
    int l = 0, len = strlen(s);
    bool trailing_space = true;

    for(int i = (len - 1) ; i >= 0 && (trailing_space || *(s + i) != ' '); --i) {
        if(*(s + i) != ' ') {
            trailing_space = false;
            ++l;
        }
    }

    return l;
}

int main()
{
    char s[101];
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        memset(s, '\0', sizeof(char) * 101);

        fastscan_string(s, n);

        int res = lengthOfLastWord(s);
        printf("%d\n", res);
    }
    return 0;
}
