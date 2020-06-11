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

        void sortColors(vector<int>& nums) const {
            int red_ptr = 0;
            int blue_ptr = nums.size() - 1;
            int curr = 0;

            while(curr <= blue_ptr) {
                if (nums[curr] == 0) {
                    int tmp = nums[curr];
                    nums[curr++] = nums[red_ptr];
                    nums[red_ptr++] = tmp;
                }
                else if (nums[curr] == 2) {
                    int tmp = nums[curr];
                    nums[curr] = nums[blue_ptr];
                    nums[blue_ptr--] = tmp;
                }
                else {
                    ++curr;
                }
            }
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

        Solution().sortColors(nums);

        for(auto& x : nums) {
            printf("%d ", x);
        }
        printf("\n");
    }

    return 0;
}
