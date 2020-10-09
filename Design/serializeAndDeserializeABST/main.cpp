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
#include <memory>
#include <numeric>
#include <optional>
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


class Robot {
    private:
        vector<vector<int>>& grid;

        int n, m;
        pair<int, int> coord;
        static constexpr int dx[] = {0, 1, 0, -1};
        static constexpr int dy[] = {1, 0, -1, 0};

        int direction;
    public:

        Robot(vector<vector<int>>& grid, pair<int, int> coord): grid(grid), n(grid.size()), m(grid[0].size()), coord(coord), direction(0) {}
        // Returns true if the cell in front is open and robot moves into the cell.
        // Returns false if the cell in front is blocked and robot stays in the current cell.
        bool move() {
            int x = 0, y = 0, xx = 0, yy = 0;
            tie(x, y) = coord;
            xx = x + dx[direction];
            yy = y + dy[direction];

            if(xx < 0 || xx >= n) return false;
            if(yy < 0 || yy >= m) return false;
            if(grid[xx][yy] == 0) return false;

            coord = make_pair(xx, yy);
            return true;
        }

        // Robot will stay in the same cell after calling turnLeft/turnRight.
        // Each turn will be 90 degrees.
        void turnLeft() {
            --direction;
            direction += 4;
            direction &= 3;
        }
        void turnRight() {
            ++direction;
            direction &= 3;
        }

        // Clean the current cell.
        void clean() {
            grid[coord.first][coord.second] = 2;
        }
};

class Solution {
    private:

        struct PairHasher {
            size_t operator()(const pair<int,int>& k) const {
                return (hash<int>()(k.first) ^ (hash<int>()(k.second) << 1)) >> 1;
            }
        };

        static constexpr int dx[] = {0, 1, 0, -1};
        static constexpr int dy[] = {1, 0, -1, 0};
        unordered_set<pair<int,int>, PairHasher> visited;

        void go_back(Robot& r) {
            r.turnRight();
            r.turnRight();
            r.move();
            r.turnRight();
            r.turnRight();
        }

        void backtrack(Robot& r, pair<int, int> cell, int d) {

            visited.insert(cell);
            r.clean();

            for(int i = 0 ; i < 4 ; ++i) {
                int x = 0 , y = 0, xx = 0, yy = 0;
                tie(x, y) = cell;
                int next_d = (d + i) % 4;
                xx = x + dx[next_d];
                yy = y + dy[next_d] ;

                if(visited.find(make_pair(xx, yy)) == visited.cend() && r.move()) {
                    backtrack(r, make_pair(xx,yy), next_d);
                    go_back(r);
                }

                r.turnRight();
            }
        }
    public:
        void cleanRoom(Robot& robot) {
            backtrack(robot, make_pair(0,0), 0);
        }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, m=0;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(auto& rows: grid) {
            for(auto& c: rows) {
                cin >> c;
            }
        }

        int x = 0, y = 0;
        cin >> x >> y;

        Robot robot(grid, make_pair(x, y));
        Solution().cleanRoom(robot);

        for(auto& rows: grid) {
            for(auto& c: rows) {
                if(c == 1) {
                    cout << "Unfinished work\n";
                    return 0;
                }
            }
        }
        cout << "Cleaned\n";
    }

    return 0;
}
