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

class Solution {
public:
    int lengthOfLIS(const vector<int>& nums) {
        auto n_size = nums.size();
        auto dp = vector<int>(n_size, 1);

        for(int i = 1 ; i < n_size ; ++i) {
            for(int j = 0; j < i ; ++j) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int res = 1;
        for(int i = 0; i < n_size ; ++i) {
            res = max(dp[i], res);
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

        auto nums = vector<int>(n, 0);
        for(int i = 0 ; i < n ; ++i) {
            fastscan(nums[i]);
        }
        auto res = Solution().lengthOfLIS(nums);
        printf("%d\n", res);
    }

    return 0;
}
