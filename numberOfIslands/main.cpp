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
    vector<vector<pair<int,int>>> par;

    pair<int, int> get_parent(int x, int y) const {
        auto i = x, j = y;
        auto p = par[i][j];
        while(p.first != i && p.second != j) {
            i = p.first;
            j = p.second;
            p = par[i][j];
        }

        return p;
    }

    void set_parent(int x, int y, const pair<int, int>& par_coord) {
        par[x][y] = par_coord;
    }

    void initialize_sets(int n, int m) {
        par = vector<vector<pair<int,int>>>(n, vector<pair<int, int>>(m, {0,0}));

        for(int i = 0; i < n ; ++i) {
            for(int j = 0 ; j < m ; ++j) {
                par[i][j] = {i,j};
            }
        }
    }
public:
    int numsIslands(const vector<vector<char>>& grid) {
        auto n = grid.size();
        if(n == 0) {
            return 0;
        }
        auto m = grid[0].size();
        initialize_sets(n, m);

        for(int i = 0; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j) {
                if(grid[i][j] == '1') {
                    auto p = {i, j};
                    if (j > 0 && grid[i][j - 1] == '1') {
                        set_parent(i, j, get_parent(i, j - 1));
                    }
                    else if (i > 0 && grid[i - 1][j] == '1') {
                        set_parent(i, j, get_parent(i - 1, j));
                    }
                }
            }
        }

        auto count = 0;
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < m ; ++j) {
                auto [x, y] = get_parent(i, j);
                if(grid[i][j] == '1' && (x == i && y == j)) {
                    ++count;
                }
            }
        }

        return count;
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
        auto grid = vector<vector<char>>(m, vector<char>(n, '0'));
        printf("n: %d, m: %d\n", n, m);


        int i;
        fl(i, 0, m){
            int j;
            fl(j, 0, n){
                cin >> grid[i][j];
                cout << grid[i][j];
            }
            cout << "\n";
        }
        cin.ignore();

        auto res = Solution().numsIslands(grid);
        printf("%d\n", res);
    }

    return 0;
}
