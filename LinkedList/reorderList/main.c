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

void reorderList(struct ListNode* head){
    if (head == NULL) {
        return;
    }

    struct ListNode* mid, *end;
    mid = end = head;

    while(end && end->next) {
        mid = mid->next;
        end = end->next->next;
    }
    struct ListNode* prev, *cur, *next;
    prev = next = NULL;
    cur = mid;
    while(cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    end = prev;
   
    cur = head;
    while(end->next) {
        next = end->next;

        end->next = cur->next;
        cur->next = end;

        cur = cur->next->next;
        end = next;
    }
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

        reorderList(&arr[0]);
        struct ListNode* res = &arr[0];

        while(res != NULL) {
            printf("%d ", res->val);
            res = res->next;
        }
        printf("\n");
    }
    return 0;
}
