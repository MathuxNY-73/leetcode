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
    Node* prev;
    Node* next;
        Node* child;

        Node(): val(0), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
    public:
        Node* flatten(Node* head) {
            auto cur = head;
            while (cur) {
                if(cur->child != nullptr) {
                    auto tmp = cur->next;
                    cur->next = flatten(cur->child);
                    cur->child = nullptr;
                    cur->next->prev = cur;
                    if (tmp) {
                        while(cur->next) cur = cur->next;
                        cur->next = tmp;
                        cur->next->prev = cur;
                    }
                }
                cur = cur->next;
            }
            return head;
        }
};


void delete_list(Node* head) {
    auto cur = head;
    while(cur) {
        if (cur->child) {
            delete_list(cur->child);
        }
        auto tmp = cur;
        if (cur->next) {
            cur->next->prev = nullptr;
        }
        cur = cur->next;
        delete tmp;
    }
}

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0;
        cin >> n;

        Node* dummy = new Node;
        Node* cur = dummy, *head = nullptr;

        bool end = true;

        wl(n) {
            string val = "\0";
            cin >> val;

            if (val == "N") {
                if (!end) {
                    end = true;
                    cur = head;
                }
                else {
                    cur = cur->next;
                }
            }
            else if (end) {
                cur->child = new Node;
                cur->child->val = stoi(val);
                head = cur->child;
                cur = cur->child;
                end = false;
            }
            else {
                cur->next = new Node;
                cur->next->prev = cur;
                cur->next->val = stoi(val);
                cur = cur->next;
            }
        }

        head = dummy->child;
        delete dummy;

        auto res = Solution().flatten(head);

        while(res) {
            cout << res->val << " ";
            res = res->next;
        }
        cout << "\n";

        delete_list(res);
        delete_list(head);
    }

    return 0;
}
