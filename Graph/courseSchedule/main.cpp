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
        bool canFinish(int numCourses, const vector<vector<int>>& prerequisites) const {
            vector<forward_list<int>> adj(numCourses, forward_list<int>());

            for (auto& e :prerequisites) {
                adj[e[0]].push_front(e[1]);
            }

            bool* cycle = new bool[numCourses];
            memset(cycle, false, sizeof(bool) * numCourses);
            for (int n = 0; n < numCourses ; ++n) {
                if (isCycle(n, adj, (bool (&)[])(*cycle))) {
                    delete[] cycle;
                    return false;
                }
            }
            delete[] cycle;
            return true;
        }


        bool isCycle(int n, vector<forward_list<int>>& adj, bool (&cycle)[]) const {
            cycle[n] = true;
            bool ret = false;
            while(!adj[n].empty() && !ret) {
                int a = adj[n].front(); adj[n].pop_front();
                if (cycle[a]) {
                    cycle[n] = false;
                    return true;
                }
                ret = isCycle(a, adj, cycle);
            }
            cycle[n] = false;
            return ret;
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


        int res = Solution().canFinish(n, prerequisites);
        printf("%s\n", res ? "True" : "False");
    }

    return 0;
}
