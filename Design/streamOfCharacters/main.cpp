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
#include <memory>
#include <numeric>
#include <optional>
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

class StreamChecker {
    private:
        struct Trie {
            array<unique_ptr<Trie>, 26> next = {};
            bool isLeaf = false;

            Trie() {}
            ~Trie() {}

            void insert(const string& word) {
                auto cur = this;
                for(auto it = word.crbegin() ; it != word.crend() ; ++it) {
                    if(!cur->next[*it - 'a']) cur->next[*it - 'a'] = make_unique<Trie>();
                    cur = cur->next[*it - 'a'].get();
                }
                cur->isLeaf = true;
            }
        };

        Trie root;
        int maxlen = 0;
        vector<char> queries;
    public:

        StreamChecker(const vector<string>& words) {
            for(auto& w: words) {
                root.insert(w);
                maxlen = std::max(maxlen, (int)w.size());
            }
        }

        bool query(char letter) {
            queries.insert(queries.begin(), letter);
            if(queries.size() > maxlen) queries.pop_back();

            auto cur = &root;
            for(auto& q: queries) {
                if(!cur->next[q - 'a']) return false;
                cur = cur->next[q - 'a'].get();
                if(cur->isLeaf) return true;
            }
            return false;
        }

};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, q=0;
        cin >> n >> q;

        vector<string> words(n);
        for(auto& w: words) {
            cin >> w;
        }

        StreamChecker sc(words);

        for(int i = 0 ; i < q ; ++i) {
            char letter = '\0';
            cin >> letter;
            cout << letter << " => " << (sc.query(letter) ? "true" : "false") << "\n";
        }
    }

    return 0;
}
