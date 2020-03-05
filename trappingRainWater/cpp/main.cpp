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
    int trap(vector<int>& height) {
        int s = height.size();
        if(s < 3) {
            return 0;
        }

        int left_max = height[0], right_max = height[s-1];
        int l = 0, r = s-1;

        int res = 0;
        while(l < r) {
            if(height[l] < height[r]) {
                if(height[l] >= left_max) left_max = height[l];
                else res += (left_max - height[l]);
                ++l;
            }
            else {
                if (height[r] >= right_max) right_max = height[r];
                else res += (right_max - height[r]);
                --r;
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

        vector<int> height(n, 0);
        for(int i = 0; i < n ; ++i) {
            fastscan(height[i]);
        }
        auto res = Solution().trap(height);
        printf("%d\n", res);
    }

    return 0;
}
