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
#include <limits>
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
    bool increasingTriplet(const vector<int>& nums) const {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        int first = std::numeric_limits<int>::max();
        int second = std::numeric_limits<int>::max();

        for (int i = 0 ; i < n ; ++i) {
            if (nums[i] > first && nums[i] > second) {
                return true;
            }
            else if (nums[i] < first) {
                first = nums[i];
            }
            else if (nums[i] > first) {
                second = nums[i];
            }
        }

        return false;
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
        auto res = Solution().increasingTriplet(nums);
        printf("%s\n", res ? "true" : "false");
    }

    return 0;
}
