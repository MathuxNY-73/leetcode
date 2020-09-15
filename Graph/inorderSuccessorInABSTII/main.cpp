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

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val): val(val), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(int val, Node* par): val(val), left(nullptr), right(nullptr), parent(par) {}

    ~Node() {
        if (left != nullptr) delete(left);
        if (right != nullptr) delete(right);
    }
};

class Solution {
    public:

        Node* inorderSuccessor(Node* node) {
            auto cur = node;
            if(cur->right) {
                cur = cur->right;
                while(cur->left) cur = cur->left;
            }
            else {
                while(cur->parent && cur->parent->right == cur) cur = cur->parent;
                cur = cur->parent;
            }
            return cur;
        }
};

Node* readBSTWithParent(int n) {
    string number;
    cin >> number;
    if(number == "N") exit(1);

    int val = stoi(number);
    Node* root = new Node(val);

    queue<Node*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i < n) {
        auto cur = q.front();
        q.pop();
        cin >> number;
        if(number != "N") {
           cur->left = new Node(stoi(number), cur);
            q.push(cur->left);
        }
        ++i;
        number.clear();

        if(i == n) break;

        cin >> number;
        if(number != "N") {
            cur->right = new Node(stoi(number), cur);
            q.push(cur->right);
        }
        ++i;
        number.clear();
    }
    return root;
}

Node* getNode(int val, Node* root) {
    auto cur = root;
    while(cur) {
        if(cur->val == val) return cur;
        else if(cur->val < val) cur = cur->right;
        else cur = cur->left;
    }
    return cur;
}

int main()
{
    int t = 0;
    cin >> t;

    wl(t)
    {
        int n = 0, val = 0;
        cin >> n >> val;

        Node* root = readBSTWithParent(n);
        Node* node = getNode(val, root);

        auto res = Solution().inorderSuccessor(node);

        cout << (res ? to_string(res->val) : "null") << "\n";

        delete(root);
    }

    return 0;
}
