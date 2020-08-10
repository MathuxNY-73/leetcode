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
        void dfs(TreeNode* root, int lvl, vector<deque<int>>& res) const {
            if (root == nullptr) {
                return;
            }
            else {
                if (lvl == res.size()) {
                    res.push_back(deque<int>());
                }

                if (lvl & 1) {
                    res[lvl].push_front(root->val);
                }
                else {
                    res[lvl].push_back(root->val);
                }

                dfs(root->left, lvl + 1, res);
                dfs(root->right, lvl + 1, res);
            }
        }
    public:
        vector<vector<int>> zigzagLevelOrderDFS(TreeNode* root) {
            vector<deque<int>> traversal;
            dfs(root, 0, traversal);

            vector<vector<int>> res;

            for(auto& q: traversal) {
                res.push_back(vector<int>(q.begin(), q.end()));
            }

            return res;
        }

        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            queue<TreeNode*> q;

            int lvl = 0;

            vector<vector<int>> res;
            q.push(root);
            while(!q.empty()) {
                int si = q.size();
                vector<int> level;

                while(si--) {
                    auto cur = q.front(); q.pop();

                    if(cur) {
                        level.push_back(cur->val);
                        q.push(cur->left);
                        q.push(cur->right);
                    }
                }

                if (lvl & 1) {
                    reverse(level.begin(), level.end());
                }

                ++lvl;
                res.push_back(level);
            }
            res.pop_back();

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

        auto res = Solution().zigzagLevelOrder(*dummy);
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
