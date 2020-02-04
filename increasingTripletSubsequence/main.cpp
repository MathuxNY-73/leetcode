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
    bool increasingTriplet(const vector<int>& nums) const {
        int n = nums.size();

        for(int i = 0 ; i < n ; ++i){
            for(int j = i + 1 ; j < n ; ++j) {
                if (nums[i] >= nums[j]) continue;
                for(int k = j + 1 ; k < n ; ++k) {
                    if (nums[j] < nums[k]) return true;
                }
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
