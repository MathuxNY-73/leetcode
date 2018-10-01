#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <stack>
#include <array>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    static bool compare(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto prio_q = std::priority_queue<ListNode*, std::vector<ListNode*>, std::function<bool(ListNode*,ListNode*)>>(compare);
        
        for(auto x: lists)
        {
            if(x != NULL)
            {
                prio_q.push(x);
            }
        }
        
        if(prio_q.empty())
        {
            return NULL;
        }
        
        auto head_node = prio_q.top();
        prio_q.pop();
        if(head_node->next != NULL)
        {
            prio_q.push(head_node->next);
        }
        auto head = new ListNode(head_node->val);
        auto cur = head;
        
        while(!prio_q.empty())
        {
            auto top_node = prio_q.top();
            prio_q.pop();
            if(top_node->next != NULL)
            {
                prio_q.push(top_node->next);
            }
            cur->next = new ListNode(top_node->val);
            cur = cur->next;
        }
        
        return head;
        
    }
};

inline void fastscan(int& number)
{
    //variable to indicate sign of input number
    bool negative = false;
    int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar_unlocked();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar_unlocked();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int k;
        fastscan(k);
        auto arr = vector<ListNode*>(k);

        int i;
        fl(i,0,k)
        {
            int n;
            fastscan(n);
            if(n == 0)
            {
                arr[i] = NULL;
                continue;
            }

            int h;
            fastscan(h);
            arr[i] = new ListNode(h);
            auto cur = arr[i];

            int j;
            fl(j, 1, n)
            {
                int c;
                fastscan(c);
                auto node = new ListNode(c);
                cur->next = node;
                cur = cur->next;
            }
        }

        auto result = Solution().mergeKLists(arr);

        auto cur = result;
        while(cur != NULL)
        {
            printf("%d ", cur->val);
            auto tmp = cur;
            cur = cur->next;
            delete(tmp);
        }

        fl(i,0,k)
        {
            cur = arr[i];
            while(cur != NULL)
            {
                auto tmp = cur;
                cur = cur->next;
                delete(tmp);
            }
        }

        printf("\n");
    }

    return 0;
}