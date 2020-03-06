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
    bool flipEquivRec(TreeNode* root1, TreeNode* root2) {
        bool equiv = false;
        if (root1 == NULL && root2 == NULL) {
            equiv = true;
        }
        else if (root1 != NULL && root2 != NULL) {
            bool equiv_l = false, equiv_r = false;
            if (root1->left != NULL) {
                if (root2->left != NULL && root1->left->val == root2->left->val) {
                    equiv_l = flipEquivRec(root1->left, root2->left);
                }
                else if (root2->right != NULL && root1->left->val == root2->right->val) {
                    equiv_l = flipEquivRec(root1->left, root2->right);
                }
            }
            else if(root2->left == NULL || root2->right == NULL) {
                equiv_l = true;
            }

            if (root1->right != NULL) {
                if (root2->left != NULL && root1->right->val == root2->left->val) {
                    equiv_r = flipEquivRec(root1->right, root2->left);
                }
                else if (root2->right != NULL && root1->right->val == root2->right->val) {
                    equiv_r = flipEquivRec(root1->right, root2->right);
                }
            }
            else if(root2->right == NULL || root2->left == NULL) {
                equiv_r = true;
            }

            equiv = equiv_l && equiv_r;
        }

        return equiv;
    }

        bool flipEquiv(TreeNode* root1, TreeNode* root2) const {
            if (root1 == NULL && root2 == NULL) {
                return true;
            }
            else if ((root1 != NULL && root2 != NULL) && root1->val == root2->val) {
                return (flipEquiv(root1->left, root2->left) &&
                    flipEquiv(root1->right, root2->right)) ||
                    (flipEquiv(root1->left, root2->right) &&
                    flipEquiv(root1->right, root2->left));
            }
            return false;
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
