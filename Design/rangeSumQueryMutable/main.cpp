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

class NumArray {
    private:
        vector<int> tree;
        int n;
    public:
        NumArray(vector<int>& nums): tree(vector<int>(nums.size() * 4 + 1, 0)), n(nums.size()) {
            for(int i = 0; i < n ; ++i) {
                update(i, nums[i]);
            }
        }

        void addVal(int v, int i, int l, int r, int val) {
            if (l == r) {
                tree[v] = val;
            }
            else {
                int m = l + ((r -l)>>1);
                if (i <= m) {
                    addVal(v * 2, i, l, m, val);
                }
                else {
                    addVal(v*2 + 1, i, m + 1, r, val);
                }
                tree[v] = tree[v * 2] + tree[2 * v + 1];
            }
        }

        void update(int i, int val) {
            addVal(1, i + 1, 1, n+1, val);
        }

        int getSum(int v, int i, int j, int l, int r) {
            if (i > j) {
                return 0;
            }
            else if (l == i && j == r) {
                return tree[v];
            }
            else {
                int m = l + ((r - l) >> 1);
                int sum = getSum(v * 2, i, min(m, j), l, m) +
                    getSum(v*2 + 1, max(i,m + 1), j, m + 1, r);
                return sum;
            }
        }

        int sumRange(int i, int j) {
            return getSum(1, i+1, j+1, 1, n+1);
        }
};

class NumArrayBit {
    private:
        vector<int> bit;
        vector<int>& mem;
    public:
        NumArrayBit(vector<int>& nums): mem(nums), bit(nums) {
            for(int i = 1 ; i < nums.size(); ++i) {
                bit[i] += bit[i - 1];
            }
            for(int i = nums.size() - 1 ; i >= 0 ; --i) {
                int ni = (i & (i + 1)) - 1;
                if(ni >= 0) bit[i] -= bit[ni];
            }
        }

        void add(int i, int val) {
            int idx = i;
            while(idx < bit.size()) {
                bit[idx] += val;
                idx |= (idx + 1);
            }
        }

        void update(int i, int val) {
            add(i, val-mem[i]);
            mem[i] = val;
        }

        int getSum(int i) {
            int res = 0;
            int idx = i;
            while(idx >= 0) {
                res += bit[idx];
                idx = (idx & (idx + 1)) - 1;
            }
            return res;
        }

        int sumRange(int i, int j) {
            return getSum(j) - getSum(i - 1);
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

        vector<int> num(n, 0);
        for(auto& e: num) {
            fastscan(e);
        }

        NumArray na(num);

        int k = 0;
        fastscan(k);
        for(int i = 0 ; i < k ; ++i) {
            int cmd = -1, val = 0;
            fastscan(cmd);

            switch(cmd) {
                case 0: {
                    int idx = 0;
                    fastscan(idx); fastscan(val);
                    na.update(idx, val);
                    break;
                }
                case 1: {
                    int start = 0, end = 0;
                    fastscan(start); fastscan(end);
                    int sum = na.sumRange(start, end);
                    printf("%d\n", sum);
                    break;
                }
                default: {
                    printf("Unknown command\n");
                    break;
                }
            }
        }
    }

    return 0;
}
