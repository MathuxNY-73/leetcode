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
        vector<int> run_in_order(const TreeNode* root) const {
            if (root == nullptr) {
                return vector<int>();
            }

            auto left = run_in_order(root->left);
            left.push_back(root->val);
            auto right = run_in_order(root->right);

            left.insert(left.end(), right.begin(), right.end());

            return left;
        }
    public:
        int kthSmallest(TreeNode* root, int k) {
            return run_in_order(root)[k -1];
        }

        int kthSmallestIter(TreeNode* root, int k) {
            stack<TreeNode*> s;
            s.push(root);

            while(!s.empty()) {
                auto cur = s.top();
                s.pop();

                while(cur) {
                    s.push(cur);
                    cur = cur->left;
                }
                cur = s.top();
                s.pop();
                if (--k == 0) {
                    return cur->val;
                }
                s.push(cur->right);
            }

            return -1;
        }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0, k = 0;
        fastscan(n);
        fastscan(k);

        TreeNode** dummy = new TreeNode*;
        readBinaryTree(dummy, n);

        int res = Solution().kthSmallestIter(*dummy, k);
        printf("%d\n", res);

        delete(*dummy);
    }

    return 0;
}
