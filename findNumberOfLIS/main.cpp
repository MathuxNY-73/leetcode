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
private:
    vector<int> tree;
public:
    int findNumberOfLIS(const vector<int>& nums) {
        auto n_size = nums.size();
        auto dp = vector<pair<int,int>>(n_size, {0,0});

        for(int i = 0 ; i < n_size ; ++i) {
            auto max_item = 0;
            auto cnt = 1;
            for(int j = 0 ; j < i ; ++j) {
                if(nums[j] < nums[i]) {
                    if(dp[j].first >  max_item) {
                        max_item = dp[j].first;
                        cnt = dp[j].second;
                    }
                     else if (dp[j].first == max_item) {
                        cnt += dp[j].second;
                    }
                }
            }
            dp[i] = {max_item + 1, cnt};
        }

        for(auto& p: dp) {
            printf("(%d %d) ", p.first, p.second);
        }
        printf("\n");

        auto max_item = max_element(dp.cbegin(), dp.cend(), [](const pair<int,int>& l, const pair<int, int>& r) -> bool {return l.first < r.first;});

        auto count = 0;
        for(int i = 0 ; i < n_size ; ++i) {
            if(dp[i].first == max_item->first) {
                count += dp[i].second;
            }
        }

        return count;
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
        auto res = Solution().findNumberOfLIS(nums);
        printf("%d\n", res);
    }

    return 0;
}
