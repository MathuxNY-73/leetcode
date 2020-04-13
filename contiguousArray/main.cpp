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
        int findMaxLength(const vector<int>& nums) {
            unordered_map<int, int> m;
            int sum = 0, max_l = 0;

            m.emplace(0, -1);

            for(int i = 0 ; i < nums.size() ; ++i) {
                sum += (nums[i] ? 1 : -1);
                auto it = m.find(sum);
                if (it == m.cend()) {
                    m.emplace(sum , i);
                }
                else {
                    max_l = max(max_l, i - it->second);
                }
            }

            return max_l;
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
