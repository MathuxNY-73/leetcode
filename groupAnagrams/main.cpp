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

class Solution {

    struct Hasher {
        static constexpr size_t P = 37;
        static constexpr size_t N = 1000000007;
        size_t operator()(const int (&value)[26]) const {
            size_t res = 0;
            size_t x = 1;
            for (auto v : value) {
                res += v * x;
                res %= N;
                x *= P;
                x %= N;
            }
            return res;
        }
    };

    size_t get_key(const string& word) const {
        int cnt[26];
        memset(cnt, 0, sizeof(int) * 26);
        for (auto& c : word) {
            ++cnt[c - 'a'];
        }
        return hash(cnt);
    }

    Hasher hash;

    public:
         vector<vector<string>> groupAnagrams(const vector<string>& strs) const {
             unordered_map<size_t, vector<string>> m_str;

             for(auto& w: strs) {
                 auto k = get_key(w);
                 m_str[k].push_back(w);
             }

             vector<vector<string>> res;
             res.reserve(m_str.size());
             for(auto& [_, v]: m_str) {
                 res.push_back(v);
             }

             return res;
        }

        vector<vector<string>> groupAnagramsSort(const vector<string>& strs) const {
            vector<string> sorted(strs);
            unordered_map<string, int> m_str;

            int idx = 0;
            for(auto& w: sorted) {
                sort(w.begin(), w.end());
                if(m_str.find(w) == m_str.cend()) {
                    m_str.emplace(w, idx++);
                }
            }

            vector<vector<string>> res(idx, vector<string>());

            for(int i = 0; i < sorted.size() ; ++i) {
                res[m_str[sorted[i]]].push_back(strs[i]);
            }
            return res;
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

        vector<string> words(n);

        for(int i = 0 ; i < n ; ++i) {
            cin >> words[i];
        }

        auto res = Solution().groupAnagrams(words);

        for(auto& g: res) {
            for(auto& w: g) {
                cout << w << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
