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

class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) const {
        unordered_map<int, int> m;
        vector<int> pool;

        for(auto& x: nums) {
            auto it = m.find(x);
            if (it == m.cend()) {
                bool rout;
                tie(it, rout) = m.insert(make_pair(x, 0));
                pool.push_back(x);
            }
            ++it->second;
        }
        auto cmp = [&m](const int& a, const int& b) -> bool {
            return m[a] < m[b];
        };
        make_heap(pool.begin(), pool.end(), cmp);

        vector<int> res;
        for(int i = 0 ; i < k ; ++i) {
            pop_heap(pool.begin(), pool.end(), cmp);
            res.push_back(pool.back());
            pool.pop_back();
        }

        return res;
    }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, k = 0;
        cin >> n >> k;

        vector<int> nums(n, 0);
        for(auto& x: nums) {
            cin >> x;
        }

        auto res = Solution().topKFrequent(nums, k);

        for(auto& x: res) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
