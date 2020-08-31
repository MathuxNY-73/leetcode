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
        int successor(TreeNode* node) {
            node = node->right;
            while(node->left) node = node->left;
            return node->val;
        }

        int predecessor(TreeNode* node) {
            node = node->left;
            while(node->right) node = node->right;
            return node->val;
        }
    public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            if(root) {
                if(root->val > key) {
                    root->left = deleteNode(root->left, key);
                }
                else if(root->val < key) {
                    root->right = deleteNode(root->right, key);
                }
                else {
                    if(root->right) {
                        root->val = successor(root);
                        root->right = deleteNode(root->right, root->val);
                    }
                    else if (root->left) {
                        root->val = predecessor(root);
                        root->left = deleteNode(root->left, root->val);
                    }
                    else {
                        delete root;
                        return nullptr;
                    }
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
        int n=0, m = 0;
        fastscan(n);
        fastscan(m);
        vector<vector<int>> maze(m, vector<int>(n, 0));
        vector<int> start(2, 0), destination(2, 0);

        for(auto& row: maze) {
            for(auto& c: row) {
                fastscan(c);
            }
        }

        for(auto& s: start) fastscan(s);
        for(auto& d: destination) fastscan(d);

        auto res = Solution().hasPath(maze, start, destination);
        printf("%s\n", res ? "True" : "False");
    }

    return 0;
}
