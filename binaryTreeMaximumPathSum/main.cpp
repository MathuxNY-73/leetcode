#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <stack>
#include <array>
#include <limits>
#include <stdexcept>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
} TreeNode;

class Solution {
private:
    int max_sum = numeric_limits<int>::min();

    int rec(TreeNode* node) {
        int val;
        if(node->left == NULL) {
            if(node->right != NULL) {
                val = max(node->val, node->val + rec(node->right));
            }
            else {
                val = node->val;
            }
            max_sum = max(val, max_sum);
        }
        else {
            auto val_l = rec(node->left);
            int val_r = 0;
            int child_max = 0;
            if(node->right != NULL) {
                val_r = rec(node->right);
                child_max = max(val_r, val_l);
            }
            else {
                child_max = val_l;
            }
            val = max(node->val, node->val + child_max);
            max_sum = max(max(val,val + min(val_l, val_r)), max_sum);
        }
        return val;
    }

public:
    int maxPathSum(TreeNode* root) {
        rec(root);
        return max_sum;
    }
};

static inline bool fastscan(int& number)
{
    //variable to indicate sign of input number
    bool negative = false;
    int c;

    number = 0;

    // extract current character from buffer
    c = getchar_unlocked();
    if (c == 'N') {
        return false;
    }

    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar_unlocked();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;

    return true;
}

static inline int fastscan_string_w(string& str, int buffer_size)
{
    char c;
    int size_of_str = 0;

    // extract current character from buffer
    c = getchar_unlocked();

    // Keep on extracting characters if they are not
    // space, carriage return or end of string
    for (; c != ' '
             && c != '\n'
             && c != '\0'
             && c != EOF;
         c=getchar_unlocked(),++size_of_str)
        {
            if(size_of_str > buffer_size)
                exit(-1);
            str.push_back(c);
        }
    return  size_of_str;
}


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

        auto res = Solution().maxPathSum(root);
        printf("%d\n", res);
        delete root;
    }

    return 0;
}
