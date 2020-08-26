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
        static constexpr int movx[] = {1, 0, -1, 0};
        static constexpr int movy[] = {0, 1, 0, -1};
    public:
        bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {

            int n = maze.size();
            if (n == 0) return false;
            int m = maze[0].size();
            if (m == 0) return false;

            int xd = destination[0], yd = destination[1];
            if((xd > 0 && maze[xd - 1][yd] != 1) &&
               (xd < n - 1 && maze[xd + 1][yd] != 1) &&
               (yd > 0 && maze[xd][yd - 1] != 1) &&
               (yd < m - 1 && maze[xd][yd + 1] != 1)) {

                return false;
            }

            stack<pair<int, int>> q;

            q.push(make_pair(start[0], start[1]));

            while(!q.empty()) {
                int x = 0, y= 0;
                tie(x,y) = q.top(); q.pop();
                if (x == destination[0] && y == destination[1])
                    return true;

                maze[x][y] = -1;

                for(int i = 0 ; i < 4 ; ++i) {
                    int xx = x;
                    int yy = y;
                    while(((xx + movx[i] >= 0 && xx + movx[i] < n) &&
                           (yy + movy[i] >= 0 && yy + movy[i] < m)) &&
                          maze[xx + movx[i]][yy + movy[i]] != 1) {
                        xx += movx[i];
                        yy += movy[i];
                    }
                    if (maze[xx][yy] == 0) {
                        q.push(make_pair(xx,yy));
                    }
                }
            }
            return false;
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
        vector<vector<int>> maze(m, vector<int>(n, 0));
        vector<int> start(2, 0), destination(2, 0);

        for(auto& row: maze) {
            for(auto& c: row) {
                fastscan(c);
            }
        }

        for(auto& s: start) fastscan(s);
        for(auto& d: destination) fastscan(d);

        auto res = Solution().hasPath(maze, start, destination);
        printf("%s\n", res ? "True" : "False");
    }

    return 0;
}
