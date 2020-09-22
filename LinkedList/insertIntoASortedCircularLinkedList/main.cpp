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

static int fast_stream = []() {
                             ios::sync_with_stdio(false);
                             cin.tie(nullptr);
                             cout.tie(nullptr);
                             return 0;
                         }();

class Node {
    public:
        int val;
        Node* next;

        Node(): next(nullptr) {}

        Node(int _val): val(_val), next(nullptr) {}

        Node(int _val, Node* _next): val(_val), next(_next) {}
};

class Solution {
    public:
        Node* insert(Node* head, int insertVal) {
            if(head == nullptr) {
                Node* node = new Node(insertVal);
                node->next = node;
                return node;
            }

            Node* c = head;
            Node* n = head->next;
            if(c == n) {
                c->next = new Node(insertVal, c);
                return head;
            }

            while(true) {
                if(n->val >= insertVal && c->val < insertVal) break;
                else if(c->val > n->val && (c->val < insertVal || insertVal <= n->val)) break;
                else if(n == head) break;
                c = n;
                n = n->next;
            }

            c->next = new Node(insertVal, n);

            return head;
        }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0,v=0;
        cin >> n >> v;

        Node dummy;
        Node* cur = &dummy;
        int i = 0;
        for(; i < n ; ++i) {
            int val = 0;
            cin >> val;
            cur->next = new Node(val);
            cur = cur->next;
        }
        if(dummy.next != nullptr) cur->next = dummy.next;

        auto h = Solution().insert(dummy.next, v);
        while(true) {
            cout << h->val << ", ";
            h = h->next;
            if(h == dummy.next) break;
        }
        cout << "\n";
        cur = dummy.next;
        while(cur) {
            if(cur->next == dummy.next) cur->next = nullptr;
            cur = cur->next;
        }

        cur = dummy.next;
        while(cur) {
            auto n = cur->next;
            delete(cur);
            cur = n;
        }
    }

    return 0;
}
