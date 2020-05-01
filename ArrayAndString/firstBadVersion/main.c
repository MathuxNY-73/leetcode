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

int longestCommonSubsequenceRec(char * text1, char * text2){
    if ((*text1 == '\0' || *text2 == '\0') ||
        (text1 == NULL || text2 == NULL)) {
        return 0;
    }
    else {
        printf("Text1 : %c and Text2: %c\n", *text1, *text2);
        if (*text1 == *text2) {
            return 1 + longestCommonSubsequenceRec(text1 + 1, text2 + 1);
        }
        else {
            return max(longestCommonSubsequenceRec(text1, text2 + 1),
                       longestCommonSubsequenceRec(text1 + 1, text2));
        }
    }
}

int longestCommonSubsequence(char * text1, char * text2){
    int dp[SIZE + 1][SIZE + 1];
    memset(dp, 0, sizeof(int) * (SIZE + 1) * (SIZE + 1));

    char* cur_1 = text1;
    int i = 1, j = 1;
    for(; cur_1 != NULL && *cur_1 != '\0' ; ++i, ++cur_1) {
        j = 1;
        char* cur_2 = text2;
        for(;cur_2 != NULL && *cur_2 != '\0'; ++j, ++cur_2) {
            //printf("Text1 : %c and Text2: %c, %d, %p\n", *cur_1, *cur_2, *cur_2, (void*)cur_2);
            if(*cur_1 == *cur_2) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[i - 1][j - 1];
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, m = 0;
        fastscan(&n);
        fastscan(&m);

        char text1[SIZE], text2[SIZE];
        memset(text1, '\0', sizeof(char) * SIZE);
        memset(text2, '\0', sizeof(char) * SIZE);

        fastscan_string_w(text1, n);
        fastscan_string_w(text2, m);

        int res = longestCommonSubsequence(text1, text2);
        printf("%d\n", res);
    }
    return 0;
}
