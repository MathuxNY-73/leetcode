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

        int hIndex(const vector<int>& citations) const {
            int n = citations.size();
            vector<int> count(n + 1, 0);

            for(auto& c: citations) {
                ++count[min(n, c)];
            }

            int k = n;
            for(int cnt = count[k] ; k > cnt ; cnt += count[k]) {
                --k;
            }

            return k;
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

        vector<int> citations(n, 0);

        for(auto& x: citations) {
            fastscan(x);
        }

        int res = Solution().hIndex(citations);

        printf("%d\n", res);
    }

    return 0;
}
