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
        TreeNode* invertTree(TreeNode* root) {
            if (root == nullptr) {
                return nullptr;
            }

            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur != nullptr) {
                    auto tmp = cur->left;
                    cur->left = cur->right;
                    cur->right = tmp;

                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            return root;
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

        auto res = Solution().invertTree(*dummy);

        queue<TreeNode*> q;
        q.push(res);

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            if (cur != nullptr) {
                printf("%d ", cur->val);

                q.push(cur->left);
                q.push(cur->right);
            }
            else {
                printf("N ");
            }
        }
        printf("\n");

        delete(*dummy);
        delete(dummy);
    }

    return 0;
}
