#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <array>
#include <fstream>
#include <forward_list>
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
        static constexpr int movx[4] = {1, 0, -1, 0};
        static constexpr int movy[4] = {0, 1, 0, -1};
    public:

        bool dfs(vector<vector<char>>& board, const string word, int d, int x, int y, int n , int m) const {
            if(d == word.size()) {
                return true;
            }

            auto tmp = board[x][y];
            board[x][y] = '0';

            for(int k = 0 ; k < 4 ; ++k) {
                int xx = max(0, min(movx[k] + x, n - 1));
                int yy = max(0, min(movy[k] + y, m - 1));

                if (board[xx][yy] == word[d]) {
                    auto exists = dfs(board, word, d + 1, xx, yy, n, m);
                    if (exists) {
                        board[x][y] = tmp;
                        return true;
                    }
                }
            }

            board[x][y] = tmp;
            return false;
        }

        bool exist(vector<vector<char>>& board, const string word) const {
            int n = board.size();
            if (!n) return false;
            int m = board[0].size();
            if (!m) return false;

            if (!word.size()) return true;

            for (int i = 0 ; i < n ; ++i) {
                for ( int j = 0 ; j < m ; ++j ) {
                    if(board[i][j] == word[0] && dfs(board, word, 1, i, j, n, m)) {
                        return true;
                    }
                }
            }
            return false;
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

        vector<vector<char>> board(n, vector<char>(m, '\0'));

        for(auto& row: board) {
            for(auto& c: row) {
                cin >> c;
            }
        }

        string word;
        cin >> word;

        auto res = Solution().exist(board, word);
        cout << (res ? "True": "False") << "\n";

    }

    return 0;
}
