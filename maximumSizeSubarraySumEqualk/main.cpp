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
            vector<int> prefix_sum(n + 1, 0);

            for(size_t i = 0 ; i < n ; ++i) {
                prefix_sum[i + 1] = nums[i] + prefix_sum[i];
            }

            int res = 0;
            for(int i = n ; i > 0 ; --i){
                for(int j = 0; j < i ; ++j) {
                    if (prefix_sum[i] - prefix_sum[j] == k) {
                        res = max(res, i - j);
                    }
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
