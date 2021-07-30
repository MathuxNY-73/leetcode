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
        int solve(const vector<vector<int>>& matrix) {
            int nb_rows = matrix.size();
            if(nb_rows == 0) return 0;
            int nb_cols = matrix[0].size();
            if(nb_cols == 0) return 0;

            vector<int> dp(nb_cols, 0);
            for(int col = 0 ; col < nb_cols ; ++col) {
                dp[col] = matrix[0][col];
            }


            int max_coins = 0;
            for(int row = 1 ; row < nb_rows ; ++row) {
                int max_col_so_far = 0;
                vector<int> next_dp(nb_cols, 0);

                for(int col = 0; col < nb_cols; ++col) {
                    if(dp[max_col_so_far] - abs(col - max_col_so_far) < dp[col]) {
                        max_col_so_far = col;
                    }

                    next_dp[col] = dp[max_col_so_far] - abs(col - max_col_so_far) + matrix[row][col];
                }

                max_col_so_far = nb_cols - 1;
                for(int col = nb_cols - 1; col >= 0 ; --col) {
                    if(dp[max_col_so_far] - abs(col - max_col_so_far) < dp[col]) {
                        max_col_so_far = col;
                    }

                    next_dp[col] = max(next_dp[col], dp[max_col_so_far] - abs(col - max_col_so_far) + matrix[row][col]);

                    max_coins = max(max_coins, next_dp[col]);
                }

                dp = next_dp;

                for(auto& cell: dp) {
                    cout << cell << ", ";
                }
                cout << "\n";
            }

            return max_coins;
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

        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(auto& row: matrix) {
            for(auto& cell: row) {
                cin >> cell;
            }
        }

        auto res = Solution().solve(matrix);

        cout << res << "\n";
    }

    return 0;
}
