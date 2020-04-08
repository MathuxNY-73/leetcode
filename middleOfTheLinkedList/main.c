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

struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }

    struct ListNode* cur = head, *m = head;

    while(cur != NULL && cur->next != NULL) {
        cur = cur->next->next;
        m = m->next;
    }
    return m;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0;
        fastscan(&n);

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

        struct ListNode* res = middleNode(&arr[0]);

        while(res != NULL) {
            printf("%d ", res->val);
            res = res->next;
        }
        printf("\n");
    }
    return 0;
}
