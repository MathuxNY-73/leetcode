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
    struct ListNode* next;
};

struct ListNode* rotateRight(struct ListNode* head, int k){
    int len = 0;
    struct ListNode* cur = head;
    while(cur != NULL) {
        ++len;
        cur = cur->next;
    }
    if(len < 2) return head;

    k %= len;

    struct ListNode* m = head, *r = head;
    int cnt = 0;
    while(r != NULL && r->next != NULL) {
        r = r->next;
        if(cnt == k) m = m->next;
        else ++cnt;
    }

    r->next = head;
    struct ListNode* res = m->next;
    m->next = NULL;

    return res;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n = 0, k = 0;
        fastscan(&n);
        fastscan(&k);

        struct ListNode* cur, *head;

        for(int i = 0 ; i < n ; ++i) {
            if(cur) {
                cur->next = malloc(sizeof(struct ListNode));
                cur = cur->next;
            }
            else {
                cur = malloc(sizeof(struct ListNode));
                head = cur;
            }
            fastscan(&(cur->val));
            cur->next = NULL;
        }

        struct ListNode* res = rotateRight(head, k);

        cur = res;
        while(cur) {
            printf("%d, ", cur->val);
            cur = cur->next;
        }
        printf("\n");

        cur = res;
        while(cur) {
            struct ListNode* to_del = cur;
            cur = cur->next;
            free(to_del);
        }
    }
    return 0;
}
