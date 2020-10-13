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

#define SIZE 101

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {

    if (node != NULL && node->next != NULL) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
    // If nodes were allocated use the following
    // struct ListNode* tmp = node->next;
    // *node = *(node->next);
    // free(tmp);
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, k = 0;
        fastscan(&n);
        fastscan(&k);

        struct ListNode arr[SIZE];
        int i = 0;
        fl(i, 0, n) {
            arr[i].next = NULL;
            if(i < n - 1) {
                arr[i].next = &arr[i+1];
            }
            arr[i].val = 0;
        }

        fl(i, 0, n) {
            fastscan(&(arr[i].val));
        }

        deleteNode(&(arr[k]));

        struct ListNode* res = &arr[0];
        while(res != NULL) {
            printf("%d ", res->val);
            res = res->next;
        }
        printf("\n");
    }
    return 0;
}
