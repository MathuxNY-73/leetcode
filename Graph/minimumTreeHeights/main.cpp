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

private:

    int dfs(int root, unordered_set<int>& visited, const unordered_map<int,vector<int>>& adj) {
        int h = 0;
        visited.insert(root);
        for(auto& c: adj.at(root)) {
            if(visited.find(c) == visited.cend()) h = max(h, dfs(c, visited, adj));
        }
        return h + 1;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0) return {};
        if(n == 1) return {0};
        if(n == 2) return {0, 1};

        unordered_map<int, vector<int>> adj;

        for(auto& edge: edges) {
            if(adj.find(edge[0]) == adj.cend()) adj[edge[0]] = vector<int>();
            adj[edge[0]].push_back(edge[1]);
            if(adj.find(edge[1]) == adj.cend()) adj[edge[1]] = vector<int>();
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> hs(n, 0);
        int min_h=numeric_limits<int>::max();
        unordered_set<int> visited;
        for(int i = 0 ; i < n ; ++i) {
            hs[i] = dfs(i, visited, adj);
            cout << "Rooted tree at i=" << i << " has h=" << hs[i] << "\n";
            min_h = min(min_h, hs[i]);
            visited.clear();
        }

        vector<int> res;
        for(int i = 0 ; i < n ; ++i) {
            if(hs[i] == min_h) res.push_back(i);
        }

        return res;
    }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, m = 0;
        cin >> n >> m;

        vector<vector<int>> edges(m, vector<int>(2, 0));
        for(auto& edge: edges) {
            cin >> edge[0] >> edge[1];
        }

        auto res = Solution().findMinHeightTrees(n, edges);
        for(auto& r: res) {
            cout << r <<", ";
        }
        cout << "\n";
    }

    return 0;
}
