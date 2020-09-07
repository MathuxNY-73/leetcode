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
    private:
        bool backtracking(const string& s, const string& pattern, int i, int j, unordered_map<char, string>& assoc, unordered_set<string> visited) {
            int n = s.length(), m = pattern.length();
            //cout << "i =" << i << " j = " <<j <<"\n";
            if(i == n && j == m) return true;
            if(i >= n || j >= m) return false;

            auto it = assoc.find(pattern[j]);
            if(it != assoc.cend()) {
                string pat = it->second;
                //cout << "For pattern[" << j << "]=" << pattern[j] << " found pat="<< pat << "\n";
                if(i + pat.length() > n || pat != s.substr(i, pat.length())) return false;

                return backtracking(s, pattern, i + pat.length(), j + 1, assoc, visited);
            }
            else {
                string new_pat = "";
                for(int l = 1 ; i + l < n ; ++l) {
                    new_pat += s[i + l - 1];
                    if(visited.count(new_pat)) continue;
                    //cout << "For pattern[" << j << "]=" << pattern[j] << " trying new_pat=" << new_pat << "\n";
                    visited.insert(new_pat);
                    assoc[pattern[j]] = new_pat;
                    if(backtracking(s, pattern, i + l, j + 1, assoc, visited)) return true;
                    visited.erase(new_pat);
                }
                assoc.erase(pattern[j]);
            }

            return false;
        }
    public:
        bool wordPatternMatch(string pattern, string s) {
            unordered_map<char, string> assoc;
            unordered_set<string> visited;
            return backtracking(s, pattern, 0, 0, assoc, visited);
        }

};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, m =0;
        cin >> m >> n;

        string pattern, s;
        pattern.reserve(m);
        s.reserve(n);

        cin >> pattern;
        cin >> s;

        bool res = Solution().wordPatternMatch(pattern, s);

        cout << (res ? "True" : "False") << "\n";
    }

    return 0;
}
