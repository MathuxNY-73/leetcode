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

typedef struct TrieNode {
    struct TrieNode* next[26];
    bool isLeaf;

    TrieNode(): isLeaf(false) {
        memset(next, 0, sizeof(struct TrieNode*) * 26);
    }

    ~TrieNode() {
        for(int i = 0 ; i < 26 ; ++i) {
            delete next[i];
        }
    }
} TrieNode;

class WordDictionary {
    private:
        TrieNode root;

    public:
        /** Initialize your data structure here. */
        WordDictionary() {

        }

        /** Adds a word into the data structure. */
        void addWord(string word) {
            auto cur = &root;

            for(auto& c: word) {
                if (cur->next[c - 'a'] == nullptr) {
                    cur->next[c - 'a'] = new TrieNode;
                }
                cur = cur->next[c - 'a'];
            }
            cur->isLeaf = true;
        }

        bool dfs(const string& word, int i, TrieNode* root) {
            if(root == nullptr) {
                return false;
            }
            else if (i == word.size()){
                return root->isLeaf;
            }
            else if (word[i] == '.') {
                for(int j = 0 ; j < 26 ; ++j) {
                    if (dfs(word, i + 1, root->next[j])) {
                        return true;
                    }
                }
            }
            else {
                return dfs(word, i + 1, root->next[word[i] - 'a']);
            }
            return false;
        }
        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
        bool search(string word) {
            return dfs(word, 0, &root);
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

        WordDictionary wd;

        for(int i = 0 ; i < n ; ++i) {
            int cmd = -1;
            cin >> cmd;

            switch(cmd) {
                case 0: {
                    string to_add = "\0"; cin >> to_add;
                    wd.addWord(to_add);
                    printf("Added %s\n", to_add.c_str());
                    break;
                }
                case 1: {
                    string to_search = "\0"; cin >> to_search;
                    bool ret_remove = wd.search(to_search);
                    printf("Search %s\n", ret_remove ? "True": "False");
                    break;
                }
                default: {
                    printf("Unknown command\n");
                    break;
                }
            }
        }
    }

    return 0;
}
