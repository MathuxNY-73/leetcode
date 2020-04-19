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
        int search(const vector<int>& nums, int target) const {
            int n = nums.size();
            if(n == 0) {
                return -1;
            }

            int l = 0, r = n - 1;

            while(l < r) {
                int m = l + ((r - l) >> 1);

                if(nums[m] > nums[r]) {
                    if(nums[r] >= target || nums[m] < target) {
                        l = m + 1;
                    }
                    else {
                       r = m;
                    }
                }
                else if (nums[m] < nums[l]) {
                    if(nums[l] <= target || nums[m] >= target) {
                        r = m;
                    }
                    else {
                        l = m + 1;
                    }
                }
                else {
                    if(nums[m] >= target) {
                        r = m;
                    }
                    else {
                        l = m + 1;
                    }
                }
            }

            return nums[r] != target ? -1 : l;
        }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0, target = 0;
        fastscan(n);
        fastscan(target);

        vector<int> nums(n, 0);

        for(auto& num: nums) {
            fastscan(num);
        }

        auto res = Solution().search(nums, target);
        printf("%d\n", res);
    }

    return 0;
}
