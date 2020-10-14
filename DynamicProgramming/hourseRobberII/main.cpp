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
    int subrob(vector<int>& nums, int s, int e) const {
        int n = nums.size();
        if(n == 0) return 0;

        int res = 0, prec = 0;
        for(int i = s ; i < e ; ++i) {
            int tmp = res;
            res = max(nums[i] + prec, res);
            prec = tmp;
        }

        return res;
    }
public:
    int rob(vector<int>& nums) const {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(subrob(nums, 1, n), subrob(nums, 0, n - 1));
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

        vector<int> houses(n, 0);

        for(auto& h: houses) {
            cin >> h;
        }

        auto res = Solution().rob(houses);

        cout << res << "\n";

    }

    return 0;
}
