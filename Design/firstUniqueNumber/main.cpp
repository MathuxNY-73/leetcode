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

typedef struct MyListNode {
    MyListNode* next, *prev;
    int val;

    MyListNode(): val(0), next(NULL), prev(NULL) {}
    MyListNode(int v): next(NULL), prev(NULL), val(v) {}

    ~MyListNode() {
        next = NULL;
        prev = NULL;
    }
} MyListNode;

class FirstUnique {
    private:
        unordered_map<int, MyListNode*> m;
        MyListNode* tail, *head;

        void add_to_list(int value) {
            auto it = m.find(value);
            if(it == m.cend()) {
                auto n = new MyListNode(value);
                if (tail == NULL && head == NULL) {
                    tail = head = n;
                }
                else {
                    tail->next = n;
                    n->prev = tail;
                    tail = n;
                }
                m.emplace(value, tail);
            }
            else {
                if (it->second != NULL) {
                    auto cur = it->second;
                    // cerr << "Node val " << cur->val << "\n";

                    if (cur->prev != NULL) {
                        cur->prev->next = cur->next;
                    }
                    if (cur->next != NULL) {
                        cur->next->prev = cur->prev;
                    }

                    if(cur == head) {
                        head = cur->next;
                    }
                    if(cur == tail) {
                        tail = cur->prev;
                    }

                    delete(cur);
                    it->second = NULL;
                }
            }
        }
    public:
        FirstUnique(const vector<int>& nums): tail(NULL), head(NULL) {
            for(auto& x: nums) {
                add_to_list(x);
            }
        }

        ~FirstUnique() {
            auto cur = head;
            while(cur != NULL) {
                auto tmp = cur->next;
                delete(cur);
                cur = tmp;
            }
        }

        int showFirstUnique() {
            if (head == NULL)
                return -1;
            return head->val;
        }
    
        void add(int value) {
            add_to_list(value);
        }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, m = 0;
        cin >> n >> m;
        vector<int> nums(m, 0);

        for(auto& x: nums) {
            cin >> x;
        }

        FirstUnique fu(nums);

        for(int i = 0 ; i < n ; ++i) {
            string cmd;

            cin >> cmd;
            //cout << "test " << cmd << "\n";
            if (cmd == "add") {
                int k = 0;
                cin >> k;

                fu.add(k);
            }
            else if(cmd == "showFirstUnique") {
                cout << fu.showFirstUnique() << "\n";
            }
        }
    }

    return 0;
}
