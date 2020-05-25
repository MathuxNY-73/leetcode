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
        vector<vector<int>> intervalIntersection(const vector<vector<int>>& A,
                                                 const vector<vector<int>>& B) const {

            if (A.size() == 0 || B.size() == 0) {
                return vector<vector<int>>(0);
            }
            int n = A.size(), m = B.size();

            auto p_a = 0, p_b = 0;

            vector<vector<int>> res;

            while (p_a < n && p_b < m) {
                int start = max(A[p_a][0], B[p_b][0]);
                int end = min(A[p_a][1], B[p_b][1]);

                if (start <= end) {
                    res.push_back({start, end});
                }

                if(A[p_a][1] < B[p_b][1]) {
                    ++p_a;
                }
                else {
                    ++p_b;
                }
            }

            res.shrink_to_fit();

            return res;
        }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0, m = 0;
        fastscan(n);

        vector<vector<int>> A(n, vector<int>(2, 0));

        for(auto& in: A) {
            fastscan(in[0]);
            fastscan(in[1]);
        }

        fastscan(m);
        vector<vector<int>> B(m, vector<int>(2, 0));

        for(auto& in: B) {
            fastscan(in[0]);
            fastscan(in[1]);
        }

        auto res = Solution().intervalIntersection(A, B);

        printf("[");
        for(auto& in: res) {
            printf("[%d, %d], ", in[0], in[1]);
        }
        printf("]\n");
    }

    return 0;
}
