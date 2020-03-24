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

struct ListNode* create_node() {
    struct ListNode* n = malloc(sizeof(struct ListNode));
    n->next = NULL;
    n->val = 0;
    return n;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l = l1;
    struct ListNode* r = l2;
    struct ListNode* dummy = create_node();
    struct ListNode* cur = dummy;

    while(l != NULL && r != NULL) {
        cur->next = create_node();
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

    while(l != NULL) {
        cur->next = create_node();
        cur = cur->next;
        cur->val = l->val;
        l = l->next;
    }

    while(r != NULL) {
        cur->next = create_node();
        cur = cur->next;
        cur->val = r->val;
        r = r->next;
    }

    struct ListNode* head = dummy->next;
    free(dummy);
    return head;
}

void free_list(struct ListNode* l) {
    while(l) {
        struct ListNode* tmp = l->next;
        free(l);
        l = tmp;
    }
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, m = 0;
        fastscan(&n);

        struct ListNode* dummy = create_node();
        struct ListNode* cur = dummy;
        while(n--) {
            cur->next = create_node();
            cur = cur->next;

            int v = 0;
            fastscan(&v);
            cur->val = v;
        }

        struct ListNode* l1 = dummy->next;
        fastscan(&m);
        cur = dummy;
        while(m--) {
            cur->next = create_node();
            cur = cur->next;

            int v = 0;
            fastscan(&v);
            cur->val = v;
        }

        struct ListNode* l2 = dummy->next;
        free(dummy);

        struct ListNode* res = mergeTwoLists(l1,l2);

        cur = res;
        while(cur) {
            printf("%d ", cur->val);
            cur = cur->next;
        }
        printf("\n");

        free_list(l1);
        free_list(l2);
        free_list(res);

    }
    return 0;
}
