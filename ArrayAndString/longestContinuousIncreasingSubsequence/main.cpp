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

using namespace std;

static int fast_stream = []() {
                             ios::sync_with_stdio(false);
                             cin.tie(nullptr);
                             cout.tie(nullptr);
                             return 0;
}();

class Solution {
public:
    int findNumberOfLCIS(const vector<int>& nums) const {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int cnt = 1, prev = nums[0], max = 1;

        for(int i = 1 ; i < n ; ++i) {
            if (nums[i] > prev) {
                ++cnt;
            }
            else {
                cnt = 1;
            }

            if (max < cnt) {
                max = cnt;
            }
            prev = nums[i];
        }

        return max;
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

        auto nums = vector<int>(n, 0);
        for(int i = 0 ; i < n ; ++i) {
            fastscan(nums[i]);
        }
        auto res = Solution().findNumberOfLCIS(nums);
        printf("%d\n", res);
    }

    return 0;
}
