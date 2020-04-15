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
        int countElements(const vector<int>& arr) const {
            unordered_set<int> s(arr.cbegin(), arr.cend());

            int res = 0;
            for(auto& x: arr) {
                if(s.find(x+1) != s.cend()) {
                    ++res;
                }
            }
            return res;
        }

        int countElementsSort(vector<int>& arr) const {
            sort(arr.begin(), arr.end());

            int res = 0;
            int num = 0, cnt = 0;
            for(auto& x: arr) {
                if(x == num) {
                    ++cnt;
                }
                else {
                    if (x == num + 1) {
                        res += cnt;
                    }
                    num = x;
                    cnt = 1;
                }
            }

            return res;
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

        vector<int> nums(n);

        for(int i = 0 ; i < n ; ++i) {
            fastscan(nums[i]);
        }

        auto res = Solution().countElementsSort(nums);

        cout << res << "\n";
    }

    return 0;
}
