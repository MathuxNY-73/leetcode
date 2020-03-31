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

        int runThruTree(TreeNode* root, int h, int m, int l, int r) {
            if(root == NULL) {
                // Should never happen
                exit(1);
            }

            //printf("h=%d, val=%d\n", h, root->val);
            if(!h) {
                return (root->left ? 1 : 0) +
                    (root->right ? 1 : 0);
            }
            else {
                int mid = l + ((r - l) >> 1);
                if (m <= mid) {
                    return runThruTree(root->left, h - 1, m, l, mid);
                }
                else {
                    return runThruTree(root->right, h - 1, m, mid + 1, r);
                }
            }
        }

    int countNodes(TreeNode* root) {
        int h = -1;
        stack<TreeNode*> s;

        s.push(root);

        while(!s.empty()) {
            auto cur = s.top();
            s.pop();

            if (cur != NULL) {
                s.push(cur->left);
                ++h;
            }
        }

        if (h == -1) {
            return 0;
        }
        if (h == 0) {
            return 1;
        }

        //printf("h=%d\n", h);
        int l = 0, r = pow(2, h - 1);
        int c = 0, cur_h = h - 1;
        TreeNode* cur = root;
        while(l <= r && cur_h >= 0) {
            int m = l + ((r - l) >> 1);
            //printf("l = %d, r = %d, cur_h=%d, m = %d\n", l, r, cur_h, m);
            c = runThruTree(cur, max(cur_h, 0), m, l, r);
            //printf("l = %d, r = %d, cur_h=%d,  m = %d and c=%d\n", l, r, cur_h, m ,c);
            //printBinaryTree(cur);
            if(c == 1) {
                return pow(2, h) + 2 * max(m - 1, 0);
            }
            else if (c == 2) {
                l = m + 1;
                cur = root->right;
            }
            else {
                r = m - 1;
                cur = root->left;
            }
            --cur_h;
        }
        //printf("h=%d, l=%d, r=%d, c=%d\n", h, l, r, c);
        return pow(2, h) - 1 + (l - 1) * 2 + c;
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

        TreeNode** root = new TreeNode*;
        readBinaryTree(root, n);
        //printBinaryTree(*root);

        int res = Solution().countNodes(*root);
        printf("%d\n", res);
        delete(*root);
        delete(root);
    }

    return 0;
}
