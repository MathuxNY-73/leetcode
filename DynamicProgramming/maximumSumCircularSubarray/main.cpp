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
        int maxSubarraySumCircular(const vector<int>& A) const {
            if (A.size() == 0) {
                return 0;
            }

            int res = numeric_limits<int>::min();
            for(int j = 0 ; j < A.size() ; ++j) {
                int curr = 0;
                for(int i = 0; i < A.size() ; ++i) {
                    curr = max(A[(i + j) % A.size()], curr + A[(i + j) % A.size()]);
                    res = max(res, curr);
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
        int n=0;
        fastscan(n);

        vector<int> A(n, 0);
        for(auto& x: A) {
            fastscan(x);
        }

        auto res = Solution().maxSubarraySumCircular(A);
        printf("%d\n", res);
    }

    return 0;
}
