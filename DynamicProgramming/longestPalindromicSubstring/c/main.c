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

#define SIZE 10000 + 1

void changeString(char* s, char* q, int s_size) {
    q[0] = '@';

    int i = 0;
    for(; i < s_size ; ++i) {
        q[2*i + 1] = '#';
        q[2*(i + 1)] = s[i];
    }

    q[2*i + 1] = '#';
    q[2*i + 2] = '$';
    q[2*i + 3] = '\0';
}

char* substr(char* s, int pos, int length) {
    /*memset(substr, '\0', sizeof(char) * (length+1));
    int i = pos;
    for(; i < pos + length ; ++i) {
        //fprintf(stderr, "%c ", s[i]);
        substr[i - pos] = s[i];
    }
    //fprintf(stderr, "i=%d\n", i);
    substr[i] = '\0';
    */
    s[pos+length] = '\0';
    return s + pos;
}

char * longestPalindrome(char * s){
    int p[2*SIZE];
    memset(p, 0, sizeof(int) * (2*SIZE));

    int s_size = 0;
    while (s[s_size] != '\0') {
        ++s_size;
    }

    char q[2*SIZE+3];
    memset(q, '\0', sizeof(char) * (2*SIZE + 3));
    changeString(s, q, s_size);

    int center = 0, r = 0;

    for(int i = 1 ; i < 2*s_size + 2; ++i) {
        int i_m = center - (i - center);

        if(r > i) {
            p[i] = min(r - i, p[i_m]);
        }

        while(q[i+1+p[i]] == q[i-1-p[i]]) {
            ++p[i];
        }

        if (i+p[i] > r) {
            center = i;
            r = i+p[i];
        }
    }

    //fprintf(stderr, "%s of size %d so %d\n", q, s_size, 2*s_size+3);
    int max_center = 0;
    int max_length = 0;

    for(int i = 1; i < 2*s_size + 2; ++i) {
        if(max_length < p[i]) {
            max_center = i;
            max_length = p[i];
        }
    }

    //fprintf(stderr,"Center is %d and length is %d\n", max_center, max_length);

    return substr(s, (max_center - 1 - max_length) / 2, max_length);
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n=0;
        fastscan(&n);
        char s[SIZE];
        memset(s, '\0', sizeof(char) * SIZE);

        fastscan_string_w(s, n);

        fprintf(stderr, "%s of size %d\n", s, n);
        char* res = longestPalindrome(s);
        printf("%s\n", res);
    }
    return 0;
}
