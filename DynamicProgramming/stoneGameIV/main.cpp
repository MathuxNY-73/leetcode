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
        bool winnerSquareGame(int n) {
            vector<bool> dp(n + 1, false);
            dp[0] = false;
            dp[1] = true;

            for(int i = 0 ; i <= n ; ++i) {
                if(dp[i]) continue;
                for(int k = 1; i + k * k <= n ; ++k) {
                    dp[i + k*k] = true;
                }
            }

            return dp[n];
        }

};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0;
        cin >> n;

        auto res = Solution().winnerSquareGame(n);
        cout << (res ? "true": "false") << "\n";
    }

    return 0;
}
