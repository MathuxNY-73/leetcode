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
    private:
        static constexpr int movx[] = {1, 0, -1, 0};
        static constexpr int movy[] = {0, 1, 0, -1};
    public:
        int orangesRotting(vector<vector<int>>& grid) const {
            int n = grid.size();
            if (!n) return -1;
            int m = grid[0].size();
            if (!m) return -1;

            int res = 0;
            queue<pair<int, int>> q;
            for(int i = 0; i < n ; ++i) {
                for (int j = 0 ; j < m ; ++j) {
                    if(grid[i][j] == 2) {
                        q.push(make_pair(i, j));
                        res = -1;
                    }
                }
            }


            while(!q.empty()) {

                int q_s = q.size();

                while(q_s--) {
                    int x = 0, y = 0;
                    tie(x, y) = q.front(); q.pop();

                    for(int i = 0 ; i < 4 ; ++i) {
                        int xx = max(0, min(x + movx[i], n - 1));
                        int yy = max(0, min(y + movy[i], m - 1));

                        if(grid[xx][yy] == 1) {
                            grid[xx][yy] = 2;
                            q.push(make_pair(xx, yy));
                        }
                    }
                }
                printf("Hello res = %d\n", res);
                ++res;
            }

            for(auto& row: grid) {
                for(auto& c: row) {
                    if(c == 1) {
                        return -1;
                    }
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
        int n=0, m = 0;
        fastscan(n);
        fastscan(m);

        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(auto& row: grid) {
            for(auto& c: row) {
                fastscan(c);
            }
        }

        int res = Solution().orangesRotting(grid);

        printf("%d\n", res);

    }

    return 0;
}
