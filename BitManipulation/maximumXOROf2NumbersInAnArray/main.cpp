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

struct TrieNode {
    array<TrieNode*, 2> children;
    bool isLeaf;
    TrieNode(): isLeaf(false) {
        for(auto& c: children) c = nullptr;
    }
    ~TrieNode() {
        for(auto& c: children) {
            if(c != nullptr) delete(c);
        }
    }
};

class Solution {
private:
    TrieNode root;
public:
    int findMaximumXOR(vector<int>& nums) {
        int xor_m = 0;

        for(auto& n: nums) {
            auto cur = &root;
            auto xor_node = &root;
            int lvl = 31, xor_num = 0;
            while(lvl >= 0) {
                int mask = 1 << lvl;
                bool is_set = n & mask;
                if (is_set) {
                    if(cur->children[1] == nullptr) {
                        cur->children[1] = new TrieNode();
                    }
                    cur = cur->children[1];
                }
                else {
                    if(cur->children[0] == nullptr) {
                        cur->children[0] = new TrieNode();
                    }
                    cur = cur->children[0];
                }

                int toggle_bit = 1 - (int)is_set;
                if(xor_node->children[toggle_bit]) {
                    xor_node = xor_node->children[toggle_bit];
                    xor_num |= (toggle_bit << lvl);
                }
                else {
                    xor_node = xor_node->children[1 - toggle_bit];
                    xor_num |= ((1 - toggle_bit) << lvl);
                }
                --lvl;
            }
            cur->isLeaf = true;
            xor_m = max(xor_m, n ^ xor_num);
        }

        return xor_m;
    }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0;
        cin >> n;

        vector<int> nums(n, 0);

        for(auto& el: nums) {
            cin >> el;
        }

        auto res = Solution().findMaximumXOR(nums);
        cout << res << "\n";
    }

    return 0;
}
