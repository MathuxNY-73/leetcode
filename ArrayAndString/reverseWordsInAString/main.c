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

char * reverseWords(char * s){
    if (s == NULL) {
        return NULL;
    }

    int start = 0, end = 0;
    int size = 0;
    while(s[size] != '\0') {
        ++size;
    }

    // Removing trailing spaces
    while(size > 0 && s[size - 1] == ' ') {
        s[size - 1] = '\0';
        --size;
    }
    end = size - 1;

    // Reverse the string
    while(start < end) {
        s[start] ^= s[end];
        s[end] ^= s[start];
        s[start] ^= s[end];
        ++start; --end;
    }

    // Reverse all the words
    int ptr = 0;
    while(ptr < size) {
        int eow = ptr, spc= 0;
        while(s[eow] == ' ' && eow < size) { ++eow; ++spc;}
        while(s[eow] != ' ' && eow < size) ++eow;
        int word = eow;
        --eow;
        while(ptr < eow) {
            s[ptr] ^= s[eow];
            s[eow] ^= s[ptr];
            s[ptr] ^= s[eow];
            --eow;++ptr;
        }
        ptr = (word - spc) + 1;
    }

    // Removing trailing spaces
    while(size > 0 && s[size - 1] == ' ') {
        s[size - 1] = '\0';
        --size;
    }

    return s;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        char sentence[SIZE];
        memset(sentence, '\0', sizeof(char) * SIZE);

        fastscan_string(sentence, n);

        char* res = reverseWords((char*)sentence);
        printf("%s\n", res);
    }
    return 0;
}
