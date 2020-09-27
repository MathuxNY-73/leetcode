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

using namespace std;

static int fast_stream = []() {
                             ios::sync_with_stdio(false);
                             cin.tie(nullptr);
                             cout.tie(nullptr);
                             return 0;
                         }();

class Solution {
    private:
        int dfs(TreeNode* n, int& sum_max) const {
            if(n == NULL) {
                return -1;
            }
            else {
                auto l = dfs(n->left, sum_max);
                auto r = dfs(n->right, sum_max);

                sum_max = max(l + r + 2, sum_max);

                return max(l, r) + 1;
            }
        }
    public:
        int diameterOfBinaryTree(TreeNode* root) const {
            int sum_max = 0;
            dfs(root, sum_max);
            return sum_max;
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

        printBinaryTree(*root);
        int res = Solution().diameterOfBinaryTree(*root);
        printf("%d\n", res);
        delete(*root);
        delete(root);
    }

    return 0;
}
