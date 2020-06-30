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

typedef struct TrieNode {
    struct TrieNode* next[26];
    bool isLeaf;
    char val;

    TrieNode(): isLeaf(false), val('\0') {
        memset(next, 0, sizeof(struct TrieNode*) * 26);
    }
    ~TrieNode() {
        for(int i = 0 ; i < 26 ; ++i) {
            if(next[i]) {
                delete next[i];
            }
        }
    }
} TrieNode;

class Solution {
    private:
        static constexpr int movx[] = {1, 0, -1, 0};
        static constexpr int movy[] = {0, 1, 0, -1};
        TrieNode root;

        void dfs(vector<vector<char>>& board, int x, int y, int n, int m, TrieNode* root, string s, vector<string>& res) const {
            if(root == nullptr) {
                return;
            }
            s.push_back(root->val);
            if (root->isLeaf) {
                res.push_back(s);
                root->isLeaf = false;
            }

            char tmp = board[x][y];
            board[x][y] = '\0';

            for(int i = 0 ; i < 4 ; ++i) {
                int xx = max(0, min(x + movx[i], n - 1));
                int yy = max(0, min(y + movy[i], m - 1));

                if (board[xx][yy] != '\0') {
                    dfs(board, xx, yy, n, m, root->next[board[xx][yy] - 'a'], s, res);
                }
            }
            board[x][y] = tmp;
        }
    public:
        void buildTrie(vector<string>& words) {
            for(auto& w: words) {
                auto cur = &root;

                for(auto& c: w) {
                    if(!cur->next[c - 'a']) {
                        cur->next[c - 'a'] = new TrieNode;
                    }
                    cur = cur->next[c - 'a'];
                    cur->val = c;
                }
                cur->isLeaf = true;
            }

        }

        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            buildTrie(words);
            vector<string> res;

            int n = board.size();
            if(n == 0) return res;
            int m = board[0].size();
            if(m == 0) return res;

            res.reserve(words.size());

            for(int i = 0; i < n ; ++i) {
                for (int j = 0; j < m ; ++j) {
                    dfs(board, i, j, n, m, root.next[board[i][j] - 'a'], string(), res);
                }
            }
            return res;

        }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, m = 0;
        cin >> n >> m;

        vector<vector<char>> board(n, vector<char>(m, '\0'));

        for(auto& row: board) {
            for(auto& c: row) {
                cin >> c;
            }
        }

        int dl = 0;
        cin >> dl;
        vector<string> words(dl, "\0");
        for(auto&w : words) {
            cin >> w;
        }

        auto res = Solution().findWords(board, words);

        for(auto& w: res) {
            cout << w << " ";
        }
        cout << "\n";

    }

    return 0;
}
