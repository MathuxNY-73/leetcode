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
        bool canJump(const vector<int>& nums) const {
            int n = nums.size();
            if (n == 0) {
                return true;
            }

            int m = 0, i = 0;

            for(i = 0 ; i < n ; ++i) {
                m = min(max(m, nums[i] + i), n - 1);
                if (i == m) {
                    break;
                }
            }

            return i == n - 1 ? true : false;
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

        vector<int> nums(n, 0);
        for(auto& x: nums) {
            fastscan(x);
        }

        auto res = Solution().canJump(nums);
        printf("%s\n", res ? "true" : "false");
    }

    return 0;
}
