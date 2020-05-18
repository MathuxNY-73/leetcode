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
            if (A.size() == 1) {
                return A[0];
            }

            int res = numeric_limits<int>::min();
            int curr = 0, p = 0;
            for(auto& x: A) {
                p += x;
                curr = x + max(curr, 0);
                res = max(res, curr);
            }

            int res1 = numeric_limits<int>::max();
            int res2 = numeric_limits<int>::max();
            int curr1 = 0, curr2 = 0;
            for(int i = 0 ; i < A.size() - 1 ; ++i) {
                curr1 = A[i+1] + min(curr1, 0);
                curr2 = A[i] + min(curr2, 0);
                res1 = min(res1, curr1);
                res2 = min(res2, curr2);
            }

            return max(res, max(p - res1, p - res2));
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
