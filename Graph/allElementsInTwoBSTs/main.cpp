#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <array>
#include <fstream>
#include <forward_list>
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
        TreeNode* morris(TreeNode* root) {
            while(root) {
                if(root->left) {
                    auto pre = root->left;
                    while(pre->right && pre->right != root) pre = pre->right;

                    if(pre->right) {
                        pre->right = NULL;
                        return root;
                    }
                    else {
                        pre->right = root;
                        root = root->left;
                    }
                }
                else {
                    return root;
                }
            }
            return root;
        }
    public:
        vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
            vector<int> res;
            auto cur1 = morris(root1), cur2 = morris(root2);

            while(cur1 && cur2) {
                //cout << cur2->val << "\n";
                if(cur1->val <= cur2->val) {
                    res.push_back(cur1->val);
                    cur1 = cur1->right;
                    cur1 = morris(cur1);
                }
                else {
                    res.push_back(cur2->val);
                    cur2 = cur2->right;
                    cur2 = morris(cur2);
                }
            }

            auto cur = cur1 == nullptr ? cur2 : cur1;
            while(cur) {
                res.push_back(cur->val);
                cur = cur->right;
                cur = morris(cur);
            }

            return res;
        }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0, m = 0;
        fastscan(n);
        fastscan(m);

        TreeNode** root1 = new TreeNode*, **root2 = new TreeNode*;
        if(n > 0) {
            readBinaryTree(root1, n);
        }
        else{
            *root1 = nullptr;
        }
        if(m > 0) {
            readBinaryTree(root2, m);
        }
        else {
            *root2 = nullptr;
        }

        auto res = Solution().getAllElements(*root1, *root2);

        for(auto& c: res) {
            printf("%d ", c);
        }
        printf("\n");

        delete(*root1); delete(root1);
        delete(*root2); delete(root2);
    }

    return 0;
}
