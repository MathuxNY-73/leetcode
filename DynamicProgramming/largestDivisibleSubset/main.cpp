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
        vector<int> largestDivisibleSubset(vector<int>& nums) const {
            if (nums.size() == 0) {
                return vector<int>();
            }
            vector<int> res, dp(nums.size(), 0);
            int max_s = 1, max_s_idx = 0;

            sort(nums.begin(), nums.end());

            for(int i = 0 ; i < nums.size() ; ++i) {
                dp[i] = 1;
                for(int j = 0 ; j < i ; ++j) {
                    if (nums[i] % nums[j] == 0) {
                        dp[i] = max(dp[i], dp[j] + 1);
                        if (dp[i] > max_s) {
                            max_s = dp[i];
                            max_s_idx = i;
                        }
                    }
                }
            }

            for(int i = max_s_idx ; i >= 0 ; --i) {
                if(dp[i] == max_s && nums[max_s_idx] % nums[i] == 0) {
                    res.emplace_back(nums[i]);
                    --max_s;
                    max_s_idx = i;
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
        int n=0;
        fastscan(n);

        vector<int> nums(n, 0);
        for(auto& x: nums) {
            fastscan(x);
        }

        auto res = Solution().largestDivisibleSubset(nums);

        for(auto& x: res) {
            printf("%d ", x);
        }
        printf("\n");
    }

    return 0;
}
