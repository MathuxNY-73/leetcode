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

class RandomizedSet {
    private:
        mt19937 gen;
        vector<int> s;
        int cnt;
        unordered_map<int, int> items;
    public:
        /** Initialize your data structure here. */
        RandomizedSet(): gen(mt19937(random_device()())),
                         cnt(0)
        {

            srand(time(nullptr));
        }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
        bool insert(int val)
        {
            if (items.find(val) != items.cend()) {
                return false;
            }
            s.push_back(val);
            items.emplace(make_pair(val, cnt++));
            return true;
        }

        /** Removes a value from the set. Returns true if the set contained the specified element. */
        bool remove(int val) {
            auto it = items.find(val);
            if(it == items.cend()) {
                return false;
            }
            s[it->second] = s[--cnt];
            items[s[it->second]] = it->second;
            items.erase(it);
            s.pop_back();
            return true;
        }

        /** Get a random element from the set. */
        int getRandom() {
            uniform_int_distribution<int> dis(1, cnt);
            int picked = dis(gen);

            return s[picked - 1];
        }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0;
        fastscan(n);

        RandomizedSet rs;

        for(int i = 0 ; i < n ; ++i) {
            int cmd = -1, val = 0;
            fastscan(cmd);

            switch(cmd) {
                case 0: {
                    fastscan(val);
                    bool ret_insert = rs.insert(val);
                    printf("%s\n", ret_insert ? "True": "False");
                    break;
                }
                case 1: {
                    fastscan(val);
                    bool ret_remove = rs.remove(val);
                    printf("%s\n", ret_remove ? "True": "False");
                    break;
                }
                case 2: {
                    int ret_rand = rs.getRandom();
                    printf("%d\n", ret_rand);
                    break;
                }
                default: {
                    printf("Unknown command\n");
                    break;
                }
            }
        }
    }

    return 0;
}
