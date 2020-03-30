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

        int runThruTree(TreeNode* r, int h, int m, int l, int r) {
            if(r == NULL) {
                // Should never happen
                exit(1);
            }

            if(!h) {
                return (r->left ? 1 : 0) +
                    (r->right ? 1 : 0);
            }
            else {
                int mid = l + ((r - l) >> 1);
                if (m =< mid) {
                    return runThruTree(r->left, h - 1, m, l, mid);
                }
                else {
                    return runThruTree(r->right, h - 1, m, mid + 1, r);
                }
            }
        }

    int countNodes(TreeNode* root) {
        int h = 0;
        stack<TreeNode*> s;

        s.push(root);

        while(!s.empty()) {
            auto cur = s.back();
            s.pop();

            if (cur != NULL) {
                s.push(cur->left);
                ++h;
            }
        }

        int l = 0, r = pow(2, h - 1);
        while(l < r) {
            int m = l + ((r - l) >> 1);
            int c = runThruTree(root, h - 1, m, l, r);
        }
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

        TreeNode** root1 = new TreeNode*;
        readBinaryTree(root1, n);

        fastscan(n);
        TreeNode** root2 = new TreeNode*;
        readBinaryTree(root2, n);

        bool res = Solution().flipEquiv(*root1, *root2);
        printf("%s\n", res ? "true": "false");
        delete(*root1);
        delete(*root2);
        delete(root1); delete(root2);
    }

    return 0;
}
