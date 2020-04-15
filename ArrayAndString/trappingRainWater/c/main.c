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

#define SIZE 10000

typedef struct Stack {
    int container[SIZE];
    int top;
} Stack;

int trap(int* height, int heightSize){
    Stack s = {.top = -1};
    memset(s.container, 0, sizeof(int) * SIZE);

    int res = 0;
    for(int i = 0; i < heightSize ; ++i) {
        while (s.top > -1 && height[s.container[s.top]] < height[i]) {
            //printf(stderr, "Removing element %d because height[%d]=%d < %d=height[%d]\n",
            //       s.container[s.top],
            //       s.container[s.top],
            //       height[s.container[s.top]],
            //       height[i],
            //       i);
            int between = s.container[s.top--];
            if(s.top == -1) break;

            int w = (min(height[s.container[s.top]], height[i]) - height[between]) * (i - s.container[s.top] - 1);
            res += w;
            //printf(stderr, "Adding %d units of water in between [%d, %d]\n", w, s.container[s.top], i);
        }

        if (s.top == SIZE - 1) {
            fprintf(stderr, "Stack is full");
            return -1;
        }

        s.container[++s.top] = i;
    }

    return res;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n=0;
        fastscan(&n);
        int* h = malloc(sizeof(int) * n);
        memset(h, 0, sizeof(int) * n);

        int i;
        fl(i,0,n) {
            fastscan(&h[i]);
        }

        for(int k = 0 ; k < n ; ++k) {
            printf("%d ", h[k]);
        }
        printf("\n");
        int res = trap(h, n);
        printf("%d\n", res);
        free(h);
    }
    return 0;
}
