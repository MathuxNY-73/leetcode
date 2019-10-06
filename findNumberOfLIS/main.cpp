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

class Solution {
private:
    pair<int, int> merge(const pair<int, int>& a, const pair<int, int>& b) const {
        if(a.first == b.first) {
            if(a.first == 0) {
                return {0, 1};
            }
            return {a.first, a.second + b.second};
        }
        return a.first > b.first ? a : b;
    }

    void insert(vector<pair<int, int>>& tree, pair<int, int> val, int key, int idx, int lo, int hi) const {
        if(lo == hi) {
            tree[idx] = merge(val, tree[idx]);
            return;
        }

        int mid = (lo + hi) / 2;

        if(key <= mid) {
            insert(tree, val, key, 2*idx + 1, lo, mid);
        }
        else {
            insert(tree, val, key, 2 * (idx + 1), mid + 1, hi);
        }

        tree[idx] = merge(tree[2*idx + 1], tree[2*(idx+1)]);
    }

    pair<int, int> query(const vector<pair<int, int>>& tree, int key, int idx, int lo, int hi) {
        auto mid = (lo + hi) / 2;

        if(key >= hi) {
            return tree[idx];
        }
        else if (key < lo) {
            return {0, 1};
        }
        else {
            return merge(query(tree, key, 2*idx + 1, lo, mid), query(tree, key, 2*(idx+1), mid + 1, hi));
        }
    }
public:
    int findNumberOfLIS(const vector<int>& nums) {
        auto n_size = nums.size();

        if(n_size == 0) {
            return 0;
        }

        auto tree = vector<pair<int, int>>(4 * n_size, {0,1});

        auto max_el = *(max_element(nums.cbegin(), nums.cend()));
        auto min_el = *(min_element(nums.cbegin(), nums.cend()));
        for(auto& el : nums) {
            auto q = query(tree, el - 1, 0, min_el, max_el);
            insert(tree, {q.first + 1, q.second}, el, 0, min_el, max_el);
        }

        return tree[0].second;
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
        auto res = Solution().findNumberOfLIS(nums);
        printf("%d\n", res);
    }

    return 0;
}
