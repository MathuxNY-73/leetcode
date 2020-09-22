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
        vector<int> majorityElementII(const vector<int>& nums) {
            int n = nums.size();
            if(n == 0) return {};

            int cand1 = 0, cand2 = 0, cnt1 = 0, cnt2 = 0;
            for(auto& e: nums) {
                if(cnt1 > 0 && cand1 == e) ++cnt1;
                else if(cnt2 > 0 && cand2 == e) ++cnt2;
                else if(cnt1 == 0) {
                    cand1 = e;
                    cnt1 = 1;
                }
                else if(cnt2 == 0) {
                    cand2 = e;
                    cnt2 = 1;
                }
                else {
                    --cnt1; --cnt2;
                }
            }

            cnt1 = cnt2 = 0;
            for(auto& e: nums) {
                if(cand1 == e) ++cnt1;
                else if(cand2 == e) ++cnt2;
            }

            vector<int> res;
            if(cnt1 > n / 3) res.push_back(cand1);
            if(cnt2 > n / 3) res.push_back(cand2);

            return res;
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
        for(auto& x: nums) {
            cin >> x;
        }

        auto res = Solution().majorityElementII(nums);
        for(auto& e: res) {
            cout << e << ", ";
        }
        cout <<"\n";
    }

    return 0;
}
