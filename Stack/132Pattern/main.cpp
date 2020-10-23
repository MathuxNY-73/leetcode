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
        bool find132pattern(const vector<int>& nums) const {
            int n = nums.size();
            if(n < 3) return false;

            stack<int> s;
            int second = numeric_limits<int>::min();

            for(int i =  n - 1; i>=0 ; --i) {
                if(nums[i] < second) return true;
                while(!s.empty() && nums[i] > s.top()) {
                    second = s.top(); s.pop();
                }
                s.push(nums[i]);
            }
            return false;
    }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0;
        cin >> n;

        vector<int> nums(n, 0);
        for(auto& c: nums) {
            cin >> c;
        }

        bool res = Solution().find132pattern(nums);

        printf("%s\n", (res?"True":"False"));

    }

    return 0;
}
