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
        int minPathSum(vector<vector<int>>& grid) const {
            if (grid.empty() || grid[0].empty()) {
                return 0;
            }

            int R = grid.size();
            int C = grid[0].size();

            for(int i = 0; i < R ; ++i) {
                for(int j = 0; j < C ; ++j) {
                    if(i > 0 && j > 0) {
                        grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                    }
                    else if (i > 0){
                        grid[i][j] += grid[i - 1][j];
                    }
                    else if (j > 0) {
                        grid[i][j] += grid[i][j - 1];
                    }
                }
            }

            return grid[R-1][C-1];
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

        vector<vector<int>> grid(n, vector<int>(m, 0));

        for(auto& r: grid) {
            for(auto& x: r) {
                fastscan(x);
            }
        }

        auto res = Solution().minPathSum(grid);
        printf("%d\n", res);
    }

    return 0;
}
