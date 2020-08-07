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
        vector<vector<int>> verticalTraversal(TreeNode* root) {

            unordered_map<int, priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>> m;
            stack<pair<TreeNode*, pair<int, int>>> s;

            int min_col = 0, max_col = 0;

            s.push(make_pair(root, make_pair(0, 0)));

            while(!s.empty()) {
                TreeNode* cur = nullptr;
                pair<int, int> p;
                int x = 0, y = 0;
                tie(cur, p) = s.top(); s.pop();
                tie(x, y) = p;

                if(cur == nullptr) continue;

                min_col = min(min_col, x);
                max_col = max(max_col, x);

                if(m.find(x) == m.cend()) {
                    m.insert(
                        make_pair(x,
                                  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>()));
                }
                m[x].push(make_pair(abs(y), cur->val));

                s.push(make_pair(cur->left, make_pair(x - 1, y - 1)));
                s.push(make_pair(cur->right, make_pair(x + 1, y - 1)));
            }

            vector<vector<int>> res(max_col - min_col + 1, vector<int>());
            for(auto& [x, pq]: m) {
                while(!pq.empty()) {
                    res[x - min_col].push_back(pq.top().second);
                    pq.pop();
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

        TreeNode** dummy = new TreeNode*;
        readBinaryTree(dummy, n);

        auto res = Solution().verticalTraversal(*dummy);
        for(auto& a: res) {
            printf("[");
            for(auto& v: a) {
                printf("%d, ", v);
            }
            printf("]");
        }
        printf("\n");
    }

    return 0;
}
