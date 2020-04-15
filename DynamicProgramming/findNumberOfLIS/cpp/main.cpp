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

typedef struct Node {
    int start;
    int end;
    struct Node* left;
    struct Node* right;
    pair<int, int> val;

    Node(int start, int end) {
        left = NULL;
        right = NULL;
        this->start = start;
        this->end = end;
        val = {0,1};
    }

    ~Node() {
        delete left;
        delete right;

        left = NULL;
        right = NULL;
    }

    struct Node& get_left() {
        if(left == NULL) {
            left = new Node(start, start + (end - start) / 2);
        }
        return *left;
    }

    struct Node& get_right() {
        if(right == NULL) {
            right = new Node(start + (end - start) / 2 + 1, end);
        }
        return *right;
    }
} Node;

class Solution {
private:
    pair<int, int> merge(const pair<int, int>& a, const pair<int, int>& b) const {
        if(a.first == b.first) {
            if(a.first == 0) {
                return {0, 1};
            }
            return {a.first, a.second + b.second};
        }
        return a.first > b.first ? a : b;
    }

    void insert(Node& tree, pair<int, int> val, int key) const {
        if(tree.start == tree.end) {
            tree.val = merge(val, tree.val);
            return;
        }

        auto mid = tree.start + (tree.end - tree.start) / 2;

        if(key <= mid) {
            insert(tree.get_left(), val, key);
        }
        else {
            insert(tree.get_right(), val, key);
        }

        tree.val = merge(tree.get_left().val, tree.get_right().val);
    }

    pair<int, int> query(Node& tree, int key) const {
        if(key >= tree.end) {
            return tree.val;
        }
        else if (key < tree.start) {
            return {0, 1};
        }
        else {
            return merge(query(tree.get_left(), key), query(tree.get_right(), key));
        }
    }
public:
    int findNumberOfLIS(const vector<int>& nums) {
        auto n_size = nums.size();

        if(n_size == 0) {
            return 0;
        }

        auto max_el = *(max_element(nums.cbegin(), nums.cend()));
        auto min_el = *(min_element(nums.cbegin(), nums.cend()));

        auto root = Node(min_el, max_el);

        for(auto& el : nums) {
            auto q = query(root, el - 1);
            printf("For %d: found (%d, %d)\n", el - 1, q.first, q.second);
            insert(root, {q.first + 1, q.second}, el);
        }

        return root.val.second;
    }

    int findNumberOfLISDP(const vector<int>& nums) const {
        auto n_size = nums.size();

        if (n_size == 0) {
            return 0;
        }

        auto dp = vector<vector<pair<int,int>>>(n_size, vector<pair<int,int>>());
        auto lis = 0;

        for(auto el: nums) {
            int l1 = 0, r = lis;// TODO: put something here
            while(l1 < r) {
                int m = (l1 + r) / 2;
                if(el <= dp[m].back().first) {
                    r = m;
                }
                else {
                    l1 = m + 1;
                }
            }

            int cnt = 1;

            if (l1 > 0) {
                int l2 = 0;
                r = dp[l1-1].size();
                int lvl = 10;
                while(l2 < r) {
                    int m = (l2 + r) / 2;
                    if(el > dp[l1-1][m].first) {
                        r = m;
                    }
                    else {
                        l2 = m + 1;
                    }
                    --lvl;
                }

                cnt = dp[l1 - 1].back().second;
                cnt -= (l2 > 0 ? dp[l1-1][l2 - 1].second : 0);
            }

            auto new_t = make_pair(el, cnt + (dp[l1].size() > 0 ? dp[l1].back().second : 0));
            dp[l1].push_back(new_t);

            if (l1==lis) {
                ++lis;
            }
        }

        return dp[lis - 1].back().second;
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

        auto nums = vector<int>(n, 0);
        for(int i = 0 ; i < n ; ++i) {
            fastscan(nums[i]);
        }
        auto res = Solution().findNumberOfLISDP(nums);
        printf("%d\n", res);
    }

    return 0;
}
