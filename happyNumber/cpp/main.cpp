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

        bool happyNumber(int num) const {
            auto s = unordered_set<int>();
            int res = 0, tmp = num;
            int max_iter = 50;
            while(res != 1 && s.find(res) == s.cend() && max_iter--) {
                s.emplace(tmp);
                res = 0;
                while(tmp) {
                    div_t d = div(tmp, 10);
                    res += (d.rem * d.rem);
                    tmp = d.quot;
                }
                tmp = res;
            }
            return res == 1;
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

        bool res = Solution().happyNumber(n);
        printf("%s\n", res ? "true": "false");
    }

    return 0;
}
