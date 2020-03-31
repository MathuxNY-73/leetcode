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

        bool runThruTree(TreeNode* root, int h, int m, int l, int r) {

            TreeNode* cur = root;
            while(h > 0) {
                int mid = l + ((r - l) >> 1);
                if (m <= mid) {
                    r = mid;
                    cur = cur->left;
                }
                else {
                    l = mid + 1;
                    cur = cur->right;
                }
                --h;
            }
            return cur != NULL;
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
        int l = 0, r = pow(2, h) - 1;
        int cur_h = h;
        TreeNode* cur = root;
        while(l <= r && cur) {
            int m = l + ((r - l) >> 1);
            //printf("Hello m=%d, cur = %p\n",m , cur);
            auto e = runThruTree(cur, cur_h, m, l, r);
            if (e) {
                l = m + 1;
                cur = cur->right;
            }
            else {
                r = m - 1;
                cur = cur->left;
            }
            --cur_h;
        }
        //printf("h=%d, l=%d, r=%d, c=%d\n", h, l, r, c);
        return pow(2, h) - 1 + l;
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
