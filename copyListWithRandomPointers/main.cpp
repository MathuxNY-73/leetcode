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
        Node* random;

        Node(): val(0), next(NULL), random(NULL) {}
        Node(int _val):val(_val), next(NULL), random(NULL){}

        void destroy() {
            if(next != NULL) {
                next->destroy();
                delete next;
                next = NULL;
            }
            random = NULL;
        }
};

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if(!head) {
                return NULL;
            }

            Node* root = new Node(head->val);

            Node* cur = root;
            Node* cur_orig = head;

            while(cur_orig != NULL) {
                cur->next = cur_orig->next;
                cur_orig->next = cur;

                cur_orig = cur->next;
                if(cur_orig != NULL) {
                    Node* n = new Node(cur_orig->val);
                    cur = n;
                }
            }

            cur = root;
            cur_orig = head;
            while(cur_orig != NULL) {
                if(cur_orig->random != NULL) {
                    cur->random = cur_orig->random->next;
                }
                cur_orig = cur->next;
                if(cur_orig != NULL) {
                    cur = cur_orig->next;
                }
            }

            cur = root;
            cur_orig = head;
            while(cur_orig != NULL){
                cur_orig->next = cur->next;
                if(cur->next != NULL) {
                    cur->next = cur->next->next;
                }
                cur = cur->next;
                cur_orig = cur_orig->next;
            }
            return root;
        }
};

int main()
{
    int t;
    fastscan(t);

    Node arr[SIZE];

    wl(t)
    {
        int n=0;
        cin >> n;

        int i = 0;
        for(; i < n ; ++i) {
            int v = 0;
            string r = "\0";

            cin >> v;
            cin >> r;

            arr[i].val = v;
            arr[i].next = &arr[i+1];
            if(r != "N") {
                arr[i].random = &arr[stoi(r)];
            }
        }
        arr[i - 1].next = NULL;

        for(int j = 0; j < n ; ++j) {
            printf("val: %d", arr[j].val);
            if(arr[j].next != NULL) {
                printf(", n=%d", arr[j].next->val);
            }
            else {
                printf(", n=NULL");
            }

            if(arr[j].random != NULL) {
                printf(", r=%d", arr[j].random->val);
            }
            else {
                printf(", r=NULL");
            }
            printf("\n");
        }

        auto res = Solution().copyRandomList(&arr[0]);

        while(res != NULL) {
            printf("val: %d", res->val);
            if(res->next != NULL) {
                printf(", n=%d", res->next->val);
            }
            else {
                printf(", n=NULL");
            }

            if(res->random != NULL) {
                printf(", r=%d", res->random->val);
            }
            else {
                printf(", r=NULL");
            }
            printf("\n");
            res = res->next;
        }
        if(res != NULL) {
            res->destroy();
            delete res;
        }
    }

    return 0;
}
