#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <array>
#include <fstream>
#include <forward_list>
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
        vector<int> findOrder(int numCourses, const vector<vector<int>>& prerequisites) const {
            int cnt = 0;
            int* deg = new int[numCourses];

            memset(deg, 0, sizeof(int) * numCourses);

            vector<vector<int>> adj(numCourses, vector<int>());
            vector<int> ret;
            stack<int> roots;

            ret.reserve(numCourses);
            for (auto& e :prerequisites) {
                adj[e[1]].push_back(e[0]);
                ++deg[e[0]];
            }

            for(int i = 0 ; i < numCourses ; ++i) {
                if (!deg[i]) {
                    roots.push(i);
                    ret.push_back(i);
                    ++cnt;
                }
            }

            while(!roots.empty()) {
                auto n = roots.top(); roots.pop();
                for(auto& x: adj[n]) {
                    if (!(--deg[x])) {
                        roots.push(x);
                        ret.push_back(x);
                        ++cnt;
                    }
                }
            }

            delete[] deg;

            return cnt == numCourses ? ret : vector<int>(0);

        }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        getchar_unlocked();

        int n=0, k = 0;
        fastscan(n);
        fastscan(k);

        vector<vector<int>> prerequisites(k, vector<int>(2));

        for(auto& x: prerequisites) {
            fastscan(x[0]);
            fastscan(x[1]);
        }


        auto res = Solution().findOrder(n, prerequisites);

        for(auto& c: res) {
            printf("%d ", c);
        }
        printf("\n");
    }

    return 0;
}
