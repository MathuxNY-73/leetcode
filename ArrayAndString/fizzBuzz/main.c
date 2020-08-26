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

char ** fizzBuzz(int n, int* returnSize){
    static const char fizz[] = "Fizz";
    static const char buzz[] = "Buzz";

    char** res = malloc(sizeof(char*) * n);
    memset(res, 0, sizeof(char*) * n);
    *returnSize = n;

    for(int i = 1 ; i <= n ; ++i) {
        if(i % 15 == 0) {
            res[i - 1] = (char*)malloc(sizeof(fizz) + sizeof(buzz));
            strcpy(res[i - 1], fizz);
            strcat(res[i - 1], buzz);
        }
        else if(i % 3 == 0) {
            res[i - 1] = (char*)malloc(sizeof(fizz));
            strcpy(res[i - 1], fizz);
        }
        else if (i % 5 == 0) {
            res[i - 1] = (char*)malloc(sizeof(buzz));
            strcpy(res[i - 1], buzz);
        }
        else {
            res[i - 1] = (char*)malloc(sizeof(char) * 10);
            memset(res[i - 1], '\0', sizeof(char) * 10);
            sprintf(res[i - 1],"%d", i);
        }
    }

    return res;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

        int returnSize = 0;
        char** res = fizzBuzz(n, &returnSize);

        for(int i = 0 ; i < returnSize ; ++i) {
            printf("%s\n", res[i]);
            free(res[i]);
        }
        free(res);
    }
    return 0;
}
