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

#define SIZE 4 * 50000

using namespace std;

static int fast_stream = []() {
                             ios::sync_with_stdio(false);
                             cin.tie(nullptr);
                             cout.tie(nullptr);
                             return 0;
                         }();

class Solution {
    public:
        int maxSubArrayLen(const vector<int>& nums, int k) {
            int n = nums.size();
            unordered_map<int, int> m;
            m.reserve(n + 1);

            m.emplace(0, -1);
            int res = 0, cum = 0;
            for(int i = 0 ; i < n ; ++i){
                cum += nums[i];
                if(m.find(cum) == m.cend()) {
                    m.emplace(cum, i);
                }
                auto it = m.find(cum - k);
                if (it != m.cend()) {
                    res = max(res, i - it->second);
                }
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
        int n=0, k = 0;
        fastscan(n);
        fastscan(k);

        vector<int> nums(n, 0);

        for(int i = 0 ; i < n ; ++i) {
            fastscan(nums[i]);
        }

        auto res = Solution().maxSubArrayLen(nums, k);
        printf("%d\n", res);
    }

    return 0;
}
