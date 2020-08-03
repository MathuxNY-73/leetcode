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

bool isPalindrome(char * s){

    int l = 0, r = -1;

    while(s[++r] != '\0');
    --r;

    while(l < r) {
        int cl = (int)(s[l] | ' ');
        int cr = (int)(s[r] | ' ');

        while(l < r && ((cl < 'a' || cl > 'z')
                        && (cl < '0' || cl > '9'))) {
            ++l;
            cl = (int)(s[l] | ' ');
        }

        while(l < r && ((cr < 'a' || cr > 'z')
                        && (cr < '0' || cr > '9'))) {
            --r;
            cr = (int)(s[r] | ' ');
        }
        if (l < r && cl != cr) return false;

        ++l;--r;
    }

    return true;
}

int main()
{
    char sentence[SIZE];
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        memset(sentence, '\0', sizeof(char) * SIZE);

        fastscan_string(sentence, n);

        bool res = isPalindrome(sentence);
        printf("%s\n", res ? "True" : "False");
    }
    return 0;
}
