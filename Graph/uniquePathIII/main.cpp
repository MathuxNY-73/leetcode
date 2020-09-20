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
    private:
        int movx[4] = {1, 0, -1, 0};
        int movy[4] = {0, 1, 0, -1};

        void dfs(vector<vector<int>>& grid, int x, int y, const int& n, const int& m, const int& valid, const int visited, int& res) {
            if(grid[x][y] == 2) {
                //cout << "End and valid=" << valid << " visited=" << visited << "\n";
                res += valid == visited;
            }
            else {
                int tmp = grid[x][y];
                grid[x][y] = -1;
                for(int i = 0 ; i < 4 ; ++i) {
                    int xx = min(n - 1, max(0, x + movx[i]));
                    int yy = min(m - 1, max(0, y + movy[i]));

                    if(grid[xx][yy] != -1) {
                        dfs(grid, xx, yy, n, m, valid, visited + 1, res);
                    }
                }
                grid[x][y] = tmp;
            }
        }
    public:
        int uniquePathsIII(vector<vector<int>>& grid) {
            int n = grid.size();
            if(n == 0) return 0;
            int m = grid[0].size();
            if(m == 0) return 0;

            int valid = 0, start_x = 0, start_y = 0;
            for(int i = 0 ; i < n ; ++i) {
                for(int j = 0 ; j < m ; ++j) {
                    if(grid[i][j] == 1) {
                        start_x = i; start_y = j;
                    }
                    valid += (grid[i][j] != -1);
                }
            }

            int res = 0;
            dfs(grid, start_x, start_y, n, m, valid, 1, res);

            return res;
        }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, m = 0;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, 0));

        for(auto& row: grid) {
            for(auto& c: row) {
                cin >> c;
            }
        }

        auto res = Solution().uniquePathsIII(grid);
        printf("%d\n", res);
    }

    return 0;
}
