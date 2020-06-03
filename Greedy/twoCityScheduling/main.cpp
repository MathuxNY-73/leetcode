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
        int twoCitySchedCost(vector<vector<int>>& costs) {
            auto cmp = [](const vector<int>& a, const vector<int>& b) {
                return a[0] - a[1] < (b[0] - b[1]);
            };
            sort(costs.begin(), costs.end(), cmp);

            int tot = 0;
            int k = costs.size() >> 1;
            for(int i = 0 ; i < k ; ++i) {
                tot += costs[i][0] + costs[i + k][1];
            }

            return tot;
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

        vector<vector<int>> costs(n, vector<int>(2, 0));
        for(auto& x: costs) {
            fastscan(x[0]);
            fastscan(x[1]);
        }

        auto res = Solution().twoCitySchedCost(costs);
        printf("%d\n", res);
    }

    return 0;
}
