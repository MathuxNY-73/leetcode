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
        int lastStoneWeight(const vector<int>& stones) const {
            priority_queue<int> q;

            for(auto x: stones) {
                q.emplace(x);
            }

            while(q.size() > 1) {
                int s1 = q.top(); q.pop();
                int s2 = q.top(); q.pop();

                q.emplace(s1 - s2);
            }

            int res = 0;
            if (!q.empty()) {
                res = q.top();
                q.pop();
            }

            return res;
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

        vector<int> stones(n, 0);

        for(int i = 0 ; i < n ; ++i) {
            fastscan(stones[i]);
        }

        auto res = Solution().lastStoneWeight(stones);
        printf("%d\n", res);
    }

    return 0;
}
