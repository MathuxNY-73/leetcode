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
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        queue<pair<int, int>> q;

        if(N == 1) res.push_back(0);

        for(int i = 1; i < 10 ; ++i) q.push(make_pair(i, 1));

        while(!q.empty()) {
            int num = 0, lvl = 0;
            tie(num, lvl) = q.front(); q.pop();

            if(lvl == N) {
                res.push_back(num);
            }
            else {
                int last = num % 10;
                if( last >= K ) q.push(make_pair(num * 10 + last - K, lvl + 1));
                if( K && last + K < 10) q.push(make_pair(num * 10 + last + K, lvl + 1));
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
        int n=0, k = 0;
        fastscan(n);
        fastscan(k);

        auto res = Solution().numsSameConsecDiff(n, k);

        for(auto& num: res) {
            printf("%d ", num);
        }
        printf("\n");
    }

    return 0;
}
