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
        int findMaxLength(const vector<int>& nums) {
            int n = nums.size();
            int res = 0;

            for(int i = 0 ; i < n ; ++i) {
                int ones = 0, zeros = 0;
                for(int j = i ; j < n ; ++j) {
                    if (nums[j]) ++ones;
                    else ++zeros;

                    if (ones == zeros) res = max(res, ones + zeros);
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

        for(int i = 0 ; i < n ; ++i) {
            fastscan(nums[i]);
        }

        auto res = Solution().findMaxLength(nums);
        printf("%d\n", res);
    }

    return 0;
}
