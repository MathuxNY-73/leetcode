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

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
    ~TreeNode() {
        if (left != NULL) {
            delete(left);
        }
        if (right != NULL) {
            delete(right);
        }
    }
} TreeNode;

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

void readBinaryTree(TreeNode**, int);
void printBinaryTree(TreeNode*);

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

void printBinaryTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
   
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        if(cur == NULL) {
            printf("N");
        }
        else {
            printf("%d", cur->val);
            q.push(cur->left);
            q.push(cur->right);
        }
        printf(" ");
    }
    printf("\n");
}

void readBinaryTree(TreeNode** r_ptr, int n) {
    string number;
    fastscan_string_w(number, 100);

    if(number == "N") {
        exit(1);
    }

    int val = stoi(number);
    TreeNode* root = new TreeNode(val);
    number.clear();

    auto q = queue<TreeNode*>();
    q.push(root);

    int i = 1;
    while(!q.empty() && i < n) {
        auto cur = q.front();
        q.pop();

        fastscan_string_w(number, 100);
        if(number != "N") {
            cur->left = new TreeNode(stoi(number));
            q.push(cur->left);
        }
        ++i;
        number.clear();

        fastscan_string_w(number, 100);
        if(number != "N") {
            cur->right = new TreeNode(stoi(number));
            q.push(cur->right);
        }
        ++i;
        number.clear();
    }
    *r_ptr = root;
}
