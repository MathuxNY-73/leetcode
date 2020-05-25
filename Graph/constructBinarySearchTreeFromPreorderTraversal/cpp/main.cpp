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

        TreeNode* construct(const vector<int>& preorder, int& idx, int par) const {
            if(idx == preorder.size() || preorder[idx] > par) {
                return NULL;
            }

            auto root = new TreeNode(preorder[idx++]);
            root->left = construct(preorder, idx, root->val);
            root->right = construct(preorder, idx, par);
            return root;
        }

        TreeNode* bstFromPreorder(const vector<int>& preorder) const {
            if(preorder.size() == 0) {
                return NULL;
            }
            int pos = 0;
            return construct(preorder, pos, numeric_limits<int>::max());

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

        vector<int> preorder(n, 0);

        for(auto& x: preorder) {
            fastscan(x);
        }

        auto res = Solution().bstFromPreorder(preorder);
        printBinaryTree(res);
        delete(res);
    }

    return 0;
}
