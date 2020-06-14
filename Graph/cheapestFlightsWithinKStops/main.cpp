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
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) const {
            vector<vector<int>> dp(n, vector<int>(K + 2, numeric_limits<int>::max()));
            vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

            for(auto& f: flights) {
                adj[f[0]].emplace_back(make_pair(f[1], f[2]));
            }

            dp[src][0] = 0;

            queue<pair<int, int>> q;
            q.push(make_pair(src, 0));

            while(!q.empty()) {
                int cur = 0, stops = 0;
                tie(cur, stops) = q.front();
                q.pop();

                for(auto& [to, c]: adj[cur]) {
                    if (dp[to][stops + 1] > dp[cur][stops] + c) {
                        dp[to][stops + 1] = dp[cur][stops] + c;

                        if (stops < K) {
                            q.push(make_pair(to, stops + 1));
                        }
                    }

                }
            }

            int res = numeric_limits<int>::max();
            for(int i = 1 ; i <= K + 1; ++i) {
                res = min(res, dp[dst][i]);
            }

            return res == numeric_limits<int>::max() ? -1 : res;

        }

};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0, src=0, dst=0, k=0;
        fastscan(n);
        fastscan(src);
        fastscan(dst);
        fastscan(k);

        vector<vector<int>> flights(n, vector<int>(3, 0));
        for(auto& f: flights) {
            fastscan(f[0]);
            fastscan(f[1]);
            fastscan(f[2]);
        }

        auto res = Solution().findCheapestPrice(n, flights, src, dst, k);
        printf("%d\n", res);
    }

    return 0;
}
