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

class BinaryMatrix {
    public:
        virtual int get(int x, int y) const = 0;
        virtual vector<int> dimensions() const = 0;
};

class BinaryMatrixImp : public BinaryMatrix {
    private:
        const vector<vector<int>> mat;
        const int n,k;
    public:
        BinaryMatrixImp(const vector<vector<int>>& m):
            mat(vector<vector<int>>(m)),
            n(m.size()),
            k(n > 0 ? m[0].size() : 0) {}

        int get(int x, int y) const {
            if(min(x,y) < 0 || x >= n || y >= k) {
                return -1;
            }
            return mat[x][y];
        }

        vector<int> dimensions() const {
            return {n, k};
        }
};

class Solution {
    public:
        int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
            auto dim = binaryMatrix.dimensions();

            if(dim[0] == 0 || dim[1] == 0) {
                return -1;
            }

            int best_c = dim[1];
            for(int i = 0; i < dim[0] ; ++i) {
                int l = 0, h = dim[1];
                while(l < h) {
                    int m = l + ((h - l) >> 1);
                    if (binaryMatrix.get(i, m)) {
                        h = m;
                    }
                    else {
                        l = m + 1;
                    }
                }
                best_c = min(best_c, h);
            }

            return best_c == dim[1] ? -1 : best_c;
        }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0, m = 0;
        fastscan(n);
        fastscan(m);

        vector<vector<int>> nums(n, vector<int>(m, 0));

        for(auto& r: nums) {
            for(auto& x: r) {
                fastscan(x);
            }
        }
        auto b = BinaryMatrixImp(nums);

        auto res = Solution().leftMostColumnWithOne(b);
        printf("%d\n", res);
    }

    return 0;
}
