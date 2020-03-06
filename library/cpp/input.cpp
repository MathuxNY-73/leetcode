#include <queue>
#include <string>

#include "input.hpp"

extern void fastscan(int&);
extern int fastscan_char_w(char(&)[], int);
extern int fastscan_string_w(std::string&, int);

void printBinaryTree(TreeNode* root) {
    std::queue<TreeNode*> q;
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
    std::string number;
    fastscan_string_w(number, 100);

    if(number == "N") {
        exit(1);
    }

    int val = stoi(number);
    TreeNode* root = new TreeNode(val);
    number.clear();

    auto q = std::queue<TreeNode*>();
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
