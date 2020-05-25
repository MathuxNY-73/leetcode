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
        int maxUncrossedLines(const vector<int>& A, const vector<int>& B) {
            vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));

            for(int i = 0 ; i < A.size() ; ++i) {
                for(int j = 0 ; j < B.size() ; ++j) {
                    if (A[i] == B[j]) {
                        dp[i][j] = 1 + (min(i, j) > 0 ? dp[i-1][j-1] : 0);
                    }
                    else {
                        dp[i][j] = max(j > 0 ? dp[i][j-1] : 0, i > 0 ? dp[i-1][j] : 0);
                    }
                }
            }

            return dp[A.size() - 1][B.size() - 1];
        }

};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0;
        fastscan(n);

        vector<int> A(n, 0);
        for(auto& x: A) {
            fastscan(x);
        }

        int m = 0;
        fastscan(m);
        vector<int> B(m, 0);
        for(auto& x: B) {
            fastscan(x);
        }

        auto res = Solution().maxUncrossedLines(A, B);
        printf("%d\n", res);
    }

    return 0;
}
