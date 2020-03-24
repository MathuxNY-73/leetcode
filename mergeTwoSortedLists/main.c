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

#define SIZE 201

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l = l1;
    struct ListNode* r = l2;
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    struct ListNode* cur = dummy;

    while(l && r) {
        cur->next = malloc(sizeof(struct ListNode));
        cur = cur->next;

        if(l->val > r->val) {
            cur->val = r->val;
            r = r->next;
        }
        else {
            cur->val = l->val;
            l = l->next;
        }
    }

    while(l) {
        cur->next = malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = l->val;
        l = l->next;
    }

    while(r) {
        cur->next = malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = r->val;
        r = r->next;
    }

    struct ListNode* head = dummy->next;
    free(dummy);
    return head;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, m = 0;
        fastscan(&n);

        struct ListNode* dummy = malloc(sizeof(struct ListNode));
        struct ListNode* cur = dummy;
        while(n--) {
            cur->next = malloc(sizeof(struct ListNode));
            cur = cur->next;

            int v = 0;
            fastscan(&v);
            cur->val = v;
        }

        struct ListNode* l1 = dummy->next;
        fastscan(&m);
        cur = dummy;
        while(m--) {
            cur->next = malloc(sizeof(struct ListNode));
            cur = cur->next;

            int v = 0;
            fastscan(&v);
            cur->val = v;
        }

        struct ListNode* l2 = dummy->next;
        free(dummy);


        bool res = backspaceCompare(S, T);
        printf("%s\n", res ? "true" : "false");
    }
    return 0;
}
