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

using namespace std;

static int fast_stream = []() {
                             ios::sync_with_stdio(false);
                             cin.tie(nullptr);
                             cout.tie(nullptr);
                             return 0;
                         }();

class Solution {
public:
    vector<int> plusOne(const vector<int>& digits) const {
        if(digits.size() == 0) {
            return digits;
        }

        int ret = 1;
        vector<int> res;
        for(auto it = digits.rbegin() ; it != digits.rend(); ++it) {
            int d = *it + ret;
            ret = d / 10;
            d -= ret * 10;
            res.push_back(d);
        }

        if (ret > 0) {
            res.push_back(ret);
        }

        reverse(res.begin(), res.end());
        return res;
    }

        vector<int> plusOneB(const vector<int>& digits) const {
            if(digits.size() == 0) {
                return digits;
            }

            long long int num = 0;
            int p = 0;
            for(auto it = digits.crbegin(); it != digits.crend() ; ++it) {
                num += pow(10, p) * (*it);
                ++p;
            }

            printf("num is %lld\n", num);
            ++num;

            vector<int> res;
            while(num > 0) {
                res.push_back(num % 10);
                num /= 10;
            }

            reverse(res.begin(), res.end());
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

        auto nums = vector<int>(n, 0);
        for(int i = 0 ; i < n ; ++i) {
            fastscan(nums[i]);
        }
        auto res = Solution().plusOneB(nums);
        for(auto& d: res) {
            printf("%d", d);
        }
        printf("\n");

    }

    return 0;
}
