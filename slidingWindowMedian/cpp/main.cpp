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
#include <limits>
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

class Solution {
public:
    vector<double> medianSlidingWindow(const vector<int>& nums, int k) {
        auto s = set<pair<int,int>, less<pair<int, int>>>();
        auto q = queue<set<pair<int, int>, less<pair<int, int>>>::const_iterator>();

        for(int i = 0 ; i < k ; ++i) {
            q.push(s.emplace(make_pair(nums[i], i)).first);
        }

        auto med_r = s.cbegin();
        auto med_l = s.cbegin();

        advance(med_l, ceil(k / 2.0) - 1);
        advance(med_r, k / 2);

        auto res = vector<double>();

        res.emplace_back(((long)med_l->first + med_r->first) / 2.0);
        for(int i = k ; i < nums.size() ; ++i) {
            auto it = q.front();
            q.pop();
            auto added = s.emplace(make_pair(nums[i], i)).first;
            //printf("Added: %d and remove: %d\n", added->first, it->first);
            q.push(added);
            if(*it >= *med_l && *added < *med_l) {
                --med_l;
            }
            if(*it <= *med_l && *added > *med_l) {
                ++med_l;
            }
            if (*it <= *med_r && *added > *med_r) {
                ++med_r;
            }
            if (*it >= *med_r && *added < *med_r) {
                --med_r;
            }
            //printf("med_l: %d, med_r: %d\n", med_l->first, med_r->first);
            s.erase(it);
            res.emplace_back(((long)med_l->first + med_r->first) / 2.0);
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
        int n=0, k = 0;
        fastscan(n);
        fastscan(k);
        auto nums = vector<int>(n, 0);

        int i;
        fl(i, 0, n){
            fastscan(nums[i]);
        }

        auto res = Solution().medianSlidingWindow(nums, k);
        for(auto& r: res) {
            printf("%f ", r);
        }
        printf("\n");
    }

    return 0;
}
