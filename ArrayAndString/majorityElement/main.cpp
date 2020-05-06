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
        int majorityElement(const vector<int>& nums) {
            unordered_map<int, int> m;
            m.reserve(nums.size());

            for(int i = 0; i < nums.size() ; ++i) {
                if(m.find(nums[i]) == m.cend()) {
                    m.emplace(nums[i], 0);
                }
                ++m[nums[i]];
            }

            int major = 0;
            for(auto&& [el, cnt] : m) {
                cout << "cnt=" << cnt << ", el=" << el << "\n";
                if (cnt > (int)(nums.size() / 2)) {
                    major = el;
                }
            }
            return major;
        }

        int majorityElementOpt(const vector<int>& nums) {
            int cnt = 0, cand = 0;

            for(auto& x: nums) {
                if (cnt == 0) {
                    cand = x;
                }
                cnt += cand == x ? 1 : -1;
            }
            return cand;
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

        cout << Solution().majorityElement(nums) << "\n";
    }

    return 0;
}
