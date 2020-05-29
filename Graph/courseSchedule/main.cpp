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
        bool canFinish(int numCourses, const vector<vector<int>>& prerequisites) {
            vector<forward_list<int>> adj(numCourses, forward_list<int>());
            unordered_set<int> cycle;
            cycle.reserve(numCourses);

            for (auto& e :prerequisites) {
                adj[e[0]].push_front(e[1]);
            }

            for (int n = 0; n < numCourses ; ++n) {
                stack<pair<int, unordered_set<int>>> s;
                unordered_set<int> c; c.reserve(numCourses);
                s.push(make_pair(n, c));

                while(!s.empty()) {
                    int cur; unordered_set<int> p;
                    tie(cur, p) = s.top(); s.pop();

                    cerr << "Poping: " << cur << "\n";
                    p.insert(cur);

                    cerr << "Adjacent nodes: ";
                    while(!adj[cur].empty()) {
                        int a = adj[cur].front(); adj[cur].pop_front();
                        cerr << a << " ";
                        if (p.find(a) != p.cend()) {
                            cerr << "Cycle !\n";
                            // A cycle exists
                            return false;
                        }
                        s.push(make_pair(a, p));
                    }
                    cerr << "\n";
                }
            }
            return true;
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
