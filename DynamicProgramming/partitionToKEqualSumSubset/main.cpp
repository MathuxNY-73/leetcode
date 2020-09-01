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
    unordered_map<int, int> getNumberOcc(const vector<int>& nums) {
        unordered_map<int, int> occ;
        for(auto&& num: nums) {
            if(occ.find(num) == occ.cend()) occ[num] = 0;
            ++occ[num];
        }
        return occ;
    }
    public:
    bool canPartitionKSubsets(const vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return false;

        int sum = 0;
        for(auto&& num: nums) sum += num;

        cout << " Sum is " << sum << "\n";
        if(sum % k != 0) return false;

        unordered_map<int,int> occ = getNumberOcc(nums);
        int sub_sum = sum / k;

        for(auto& [k,v]: occ) {
            if(v == 0) continue;

            int diff = sub_sum - k;
            auto it = occ.find(diff);

            if(diff < 0) return false;
            else if(diff == 0) continue;

            if(it == occ.cend() || it->second == 0) return false;
            --it->second;
            --v;
        }

        return true;
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
