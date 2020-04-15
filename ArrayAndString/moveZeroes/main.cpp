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
        void moveZeroes(vector<int>& nums) const {

            for(auto i = nums.begin(), iz = nums.begin() ;
                i != nums.end() ; ++i) {
                if(i != iz) {
                    *iz += *i;
                    *i -= *iz;
                }
                iz += (*iz ? 1 : 0);
            }
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

        vector<int> nums(n, 0);

        for(auto& e: nums) {
            fastscan(e);
        }

        Solution().moveZeroes(nums);

        for(auto& e: nums) {
            printf("%d ", e);
        }
        printf("\n");
    }

    return 0;
}
