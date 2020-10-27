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

struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL) return NULL;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL) {
        slow = slow->next;
        if(fast->next == NULL) return NULL;
        fast = fast->next->next;

        if(fast == slow) break;
    }
    if(fast == NULL) return NULL;


    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = slow;

    while(ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, pos = 0;
        fastscan(&n);
        fastscan(&pos);

        struct ListNode arr[SIZE];
        struct ListNode* cycle = NULL;
        int i = 0;
        fl(i, 0, n) {
            arr[i].next = NULL;
            if(i == pos) {
                cycle = &arr[i];
            }

            if(i < n - 1) {
                arr[i].next = &arr[i+1];
            }
            else {
                arr[i].next = cycle;
            }
            arr[i].val = 0;
        }

        fl(i, 0, n) {
            fastscan(&(arr[i].val));
        }

        struct ListNode* res = detectCycle(&arr[0]);


        if(res == NULL) printf("-1\n");
        else {
            int i = 0;
            while(&arr[i] != res) ++i;
            printf("%d, %d\n", res->val, i);
        }
    }
    return 0;
}
