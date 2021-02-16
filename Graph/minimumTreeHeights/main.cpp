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

    void bfs(int n, const unordered_map<int,vector<int>>& adj, vector<int>& deg, vector<bool>& visited) {
        queue<int> q;
        for(auto& [k, v]: adj) {
            if(deg[k] == 1) q.push(k);
        }

        while(!q.empty() && n > 2) {
            int q_s = q.size();
            while(q_s--) {
                int cur = q.front(); q.pop();
                if(visited[cur]) continue;
                visited[cur]= true;
                --n;
                for(auto& c: adj.at(cur)) {
                    if(--deg[c] == 1) q.push(c);
                }
            }
        }
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0) return {};
        if(n == 1) return {0};
        if(n == 2) return {0, 1};

        unordered_map<int, vector<int>> adj;
        vector<int> deg(n, 0);

        for(auto& edge: edges) {
            if(adj.find(edge[0]) == adj.cend()) adj[edge[0]] = vector<int>();
            adj[edge[0]].push_back(edge[1]);
            if(adj.find(edge[1]) == adj.cend()) adj[edge[1]] = vector<int>();
            adj[edge[1]].push_back(edge[0]);
            ++deg[edge[0]];
            ++deg[edge[1]];
        }

        vector<bool> visited(n, false);
        bfs(n, adj, deg, visited);
        vector<int> res;
        for(int i =0 ; i < n; ++i) {
            if(!visited[i]) res.push_back(i);
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
