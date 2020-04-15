#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "input.hpp"

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v):val(v), next(NULL) {}
} ListNode;

class Solution {
private:
    ListNode* removeNthFromEndRec(ListNode* node, int* n) {
        if(node != NULL) {
            auto ch = removeNthFromEndRec(node->next, n);
            if(*n == -1) {
                node->next = ch->next;
            }
        }
        --(*n);
        return node;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 0) {
            return head;
        }
        auto root = ListNode(-1);
        root.next = head;
        return removeNthFromEndRec(&root, &n)->next;
    }

    ListNode* removeNthFromEndOnePass(ListNode* head, int n) {
        if(n == 0) {
            return head;
        }
        auto dummy = ListNode(-1);
        dummy.next = head;

        auto first = dummy.next;
        auto second = &dummy;

        auto cnt = 0;
        while(cnt < n) {
            first = first->next;
            ++cnt;
        }

        while(first != NULL) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;

        return dummy.next;
    }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0,r=0;
        fastscan(n);
        fastscan(r);

        ListNode* cur = NULL;
        ListNode* head = NULL;
        for(int i = 0 ; i < n ; ++i) {
            int x;
            fastscan(x);
            auto l = ListNode(x);
            auto tmp = (ListNode*)malloc(sizeof(ListNode));
            *tmp = l;
            if(i == 0) {
                cur = tmp;
                head = tmp;
            }
            else {
                cur->next = tmp;
            }
            cur = tmp;
        }

        auto res = Solution().removeNthFromEndOnePass(head, r);

        cur = res;
        while(cur != NULL) {
            auto tmp = cur->next;
            printf("%d ", cur->val);
            free(cur);
            cur = tmp;
        }
        printf("\n");
    }

    return 0;
}
