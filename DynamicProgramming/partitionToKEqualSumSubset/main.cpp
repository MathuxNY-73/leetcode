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
    private:
    bool search(int n, const vector<int>& nums, vector<bool>& dp, vector<bool>& visited, int goal, int combi, int& target) {
        if(!visited[combi]) {
            visited[combi] = true;
            int subgoal = (goal - 1) % target + 1;
            for(int i = 0 ; i < n ; ++i) {
                if((combi & (1 << i)) == 0 && nums[i] <= subgoal) {
                    if(search(n, nums, dp, visited, goal - nums[i], combi | (1 << i), target)) {
                        dp[combi] = true;
                        break;
                    }
                }
            }
        }
        return dp[combi];
    }
    public:
    bool canPartitionKSubsets(const vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return false;

        int sum = 0;
        for(auto&& num: nums) sum += num;

        cout << " Sum is " << sum << "\n";
        if(sum % k != 0) return false;
        int target = sum / k;

        for(auto& num: nums) {
            if(num > target) return false;
        }

        vector<bool> dp(1<<n, false), visited(1 << n, false);
        dp[(1<<n) - 1] = true;
        return search(n, nums, dp, visited, sum, 0, target);
    }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, k = 0;
        cin >> n >> k;

        vector<int> nums(n, 0);
        for(auto& c: nums) {
            cin >> c;
        }

        auto res = Solution().canPartitionKSubsets(nums, k);
        printf("%s\n", (res? "True" : "False"));
    }

    return 0;
}
