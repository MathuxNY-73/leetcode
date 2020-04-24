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

typedef struct ListNode {
    ListNode* next, *prev;
    int val, key;

    ListNode(): val(0), key(-1), next(NULL), prev(NULL) {}
    ListNode(int k, int v): next(NULL), prev(NULL), key(k), val(v) {}

    ~ListNode() {
        next = NULL;
        prev = NULL;
    }
} ListNode;

class LRUCache {
    private:
        unordered_map<int, ListNode*> cache;
        ListNode* mru, *lru;
        int capacity, cnt;
    public:
        LRUCache(int capacity): cache(unordered_map<int, ListNode*>()), mru(NULL), lru(NULL), capacity(capacity), cnt(0) {
            cache.reserve(capacity);
        }

        ~LRUCache() {
            auto cur = lru;
            while(cur != NULL) {
                auto tmp = cur->next;
                delete(cur);
                cur = tmp;
            }
        }

        int get(int key) {
            auto it = cache.find(key);
            if (it == cache.cend()) {
                return -1;
            }

            auto n = it->second;

                //cout << "Node key="<< n->key << " val=" <<n->val << "\n";
                //cout << "LRU key=" << lru->key << " val=" << lru->val << "\n";
                //cout << "MRU key=" << mru->key << " val=" << mru->val << "\n";
            if(n->key != mru->key) {
                if(n->prev == NULL) {
                    lru = n->next;
                }
                else {
                    n->prev->next = n->next;
                }

                n->next->prev = n->prev;
               
                mru->next = n;
                n->prev = mru;
                n->next = NULL;
                mru = n;
            }

            return mru->val;
        }

        void put(int key, int value) {
            auto it = cache.find(key);
            if (it == cache.cend()) {
                if(cnt < capacity) {
                    auto node = new ListNode(key, value);
                    if(mru == NULL) {
                        mru = node;
                        lru = node;
                    }
                    else {
                        mru->next = node;
                        node->prev = mru;
                        mru = node;
                    }
                    ++cnt;
                }
                else {
                    cache.erase(lru->key);

                    lru->val = value;
                    lru->key = key;

                    if(lru->next != NULL) {
                        // Capacity > 1
                        lru->next->prev = NULL;
                        lru->prev = mru;
                        mru->next = lru;
                        mru = lru;
                        lru = lru->next;
                        mru->next = NULL;
                    }
                }

                cache[key] = mru;
            }
            else {
                auto n = it->second;
                if(n->key != mru->key) {
                    if(n->prev == NULL) {
                        lru = n->next;
                    }
                    else {
                        n->prev->next = n->next;
                    }

                    n->next->prev = n->prev;

                    mru->next = n;
                    n->prev = mru;
                    n->next = NULL;
                    mru = n;
                }
                mru->val = value;
            }

            //auto cur = lru;
            //while(cur!= NULL) {
            //    cout << "Node key="<< cur->key << " val=" <<cur->val << "\n";
            //    cur=cur->next;
            //}
        }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, capacity = 0;
        cin >> n >> capacity;
        LRUCache cache(capacity);

        for(int i = 0 ; i < n ; ++i) {
            string cmd;

            cin >> cmd;
            //cout << "test " << cmd << "\n";
            if (cmd == "get") {
                int k = 0;
                cin >> k;

                cout << cache.get(k) << "\n";
            }
            else if(cmd == "put") {
                int k = 0, v = 0;
                cin >> k >> v;
                cache.put(k, v);
            }
        }
    }

    return 0;
}
