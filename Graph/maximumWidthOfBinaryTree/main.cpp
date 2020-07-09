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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        queue<pair<TreeNode*, long int>> q;
        q.push({root,0});
        int ans = 0;

        while(!q.empty()) {
            unsigned long long int min_idx = numeric_limits<long int>::max(), max_idx = 0;
            int q_s = q.size();
            for(int i = 0 ; i < q_s ; ++i) {
                struct TreeNode* cur = nullptr;
                unsigned long long int idx = 0;
                tie(cur, idx) = q.front();
                q.pop();

                min_idx = min(idx, min_idx);
                max_idx = max(idx, max_idx);
                ans = max(ans, (int)(max_idx - min_idx + 1));

                if (cur->left != nullptr) {
                    q.push({cur->left, idx * 2ULL});
                }
                if (cur->right != nullptr) {
                    q.push({cur->right, idx * 2ULL + 1ULL});
                }
            }
        }

        return ans;
    }

    int widthOfBinaryTreeNoIndex(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while(!q.empty()) {
            int q_s = q.size(), min_idx = -1;
            for(int i = 0 ; i < q_s ; ++i) {
                struct TreeNode* cur = NULL;
                cur = q.front();
                q.pop();

                if (cur != nullptr) {
                    if (min_idx == -1) {
                        min_idx = i;
                        ans = max(ans, 1);
                    }
                    else {
                        ans = max(ans, i - min_idx + 1);
                    }
                }

                if (min_idx != -1) {
                    if (cur == nullptr) {
                        q.push(nullptr); q.push(nullptr);
                    }
                    else {
                        q.push(cur->left);
                        q.push(cur->right);
                    }
                }
            }
        }

        return ans;

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

        int res = Solution().widthOfBinaryTree(*dummy);
        printf("%d\n", res);
    }

    return 0;
}
