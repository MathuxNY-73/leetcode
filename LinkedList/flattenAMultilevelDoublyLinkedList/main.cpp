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
            if (head == nullptr) {
                return nullptr;
            }

            Node* dummy = new_node();
            Node* tail = dummy;

            stack<Node*> s;
            s.push(head);

            while(!s.empty()) {
                auto cur = s.top();
                s.pop();

                if (cur->next != nullptr) {
                    s.push(cur->next);
                }

                if (cur->child != nullptr) {
                    s.push(cur->child);
                }

                tail->next = new_node();
                tail->next->prev = tail;
                tail->next->val = cur->val;
                tail = tail->next;
            }

            auto res = dummy->next;
            res->prev = nullptr;
            delete dummy;
            return res;
        }

        Node* new_node() const {
            auto node = new Node;
            node->val = 0;
            node->prev = nullptr;
            node->next = nullptr;
            node->child = nullptr;
            return node;
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
