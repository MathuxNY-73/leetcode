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
#define SIZE 1001

using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }

        ListNode* cur = head;
        while(cur != nullptr) {
            if(cur->next != nullptr && cur->next->val == val) {
                auto tmp = cur->next;
                cur->next = cur->next->next;

                tmp->next = nullptr;
                delete tmp;
            }
            else {
                cur = cur->next;
            }
        }

        if (head->val == val) {
            auto tmp = head;
            head = head->next;

            tmp->next = nullptr;
            delete tmp;
        }

        return head;
    }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0,val = 0;
        fastscan(n);
        fastscan(val);

        ListNode dummy;
        ListNode* cur = &dummy;
        
        for(int i = 0 ; i < n; ++i) {
            int x;
            fastscan(x);
            cur->next = new ListNode(x);
            cur = cur->next;
        }

        auto res = Solution().removeElements(dummy.next, val);

        cur = res;
        while(cur != nullptr) {
            auto tmp = cur;
            printf("%d ", cur->val);
            cur = cur->next;

            tmp->next = nullptr;
            delete tmp;
        }
        printf("\n");
    }

    return 0;
}
