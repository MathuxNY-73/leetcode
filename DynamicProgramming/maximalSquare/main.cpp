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
        int maximalSquare(const vector<vector<char>>& matrix) const {
            if(matrix.size() == 0 || matrix[0].size() == 0) {
                return 0;
            }

            int n = matrix.size(), m = matrix[0].size();

            vector<vector<int>> dp(n, vector<int>(m , 0));

            int i = 0, j = 0, res = 0;
            for(i = 0; i < n ; ++i) {
                for(j = 0 ; j < m ; ++j) {
                    if(matrix[i][j] == '1') {
                        dp[i][j] = 1 + min(min(i > 0 ? dp[i-1][j] : 0,
                                            j > 0 ? dp[i][j-1] : 0),
                                        i > 0 && j > 0 ? dp[i-1][j-1] : 0);
                        res = max(res, dp[i][j]);
                    }
                }
            }

            return res * res;
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

        vector<vector<char>> matrix(n, vector<char>(m, '0'));

        for(auto& r: matrix) {
            for(auto& x: r) {
                cin >> x;
            }
        }

        auto res = Solution().maximalSquare(matrix);
        printf("%d\n", res);
    }

    return 0;
}
