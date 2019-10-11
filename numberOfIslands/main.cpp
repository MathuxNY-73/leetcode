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
#define min(a,b) a < b ? a : b
#define max(a,b) a < b ? b : a
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

class Solution {
public:
    static int findMin(const vector<int>& nums) {
        return *min_element(nums.cbegin(), nums.cend());
    }

    static int findMinBin(const vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l < r) {
            auto m = l + (r - l) / 2;
            if(nums[m] >= nums[l] && nums[m] > nums[r]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        return nums[l];
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

        int i;
        fl(i, 0, n){
            fastscan(nums[i]);
        }

        int res = Solution::findMinBin(nums);
        printf("%d\n", res);
    }

    return 0;
}
