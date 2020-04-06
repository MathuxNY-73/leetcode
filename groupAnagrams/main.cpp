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
    public:
        vector<vector<string>> groupAnagrams(const vector<string>& strs) const {
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
