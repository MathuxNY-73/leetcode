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

class Solution {
private:
    int treeDFS(const struct TreeNode* root, int sum) {

        if(root == NULL) {
            return 0;
        }

        sum = sum * 10 + root->val;

        if(root->left ==  NULL && root->right == NULL) {
            return sum;
        }
        else {
            int l = treeDFS(root->left, sum);
            int r = treeDFS(root->right, sum);

            return r+l;
        }
    }

public:
    int sumNumbers(const struct TreeNode* root){
        return treeDFS(root, 0);
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

        string number;
        fastscan_string_w(number, 100);

        if(number == "null") {
            exit(1);
        }
        int val = stoi(number);
        auto root = new TreeNode(val);
        number.clear();

        auto q = queue<TreeNode*>();
        q.push(root);

        int i = 1;
        while(!q.empty() && i < n) {
            auto cur = q.front();
            q.pop();

            fastscan_string_w(number, 100);
            printf("Left of %d is %s\n", cur->val, number.c_str());
            if(number == "null") {
                cur->left = NULL;
            }
            else {
                cur->left = new TreeNode(stoi(number));
            }
            number.clear();
            q.push(cur->left);
            ++i;

            fastscan_string_w(number, 100);
            printf("Right of %d is %s\n", cur->val, number.c_str());
            if(number == "null") {
                cur->right = NULL;
            }
            else {
                cur->right = new TreeNode(stoi(number));
            }
            number.clear();
            q.push(cur->right);
            ++i;
        }

        auto res = Solution().sumNumbers(root);
        printf("%d\n", res);
        delete root;
    }

    return 0;
}
