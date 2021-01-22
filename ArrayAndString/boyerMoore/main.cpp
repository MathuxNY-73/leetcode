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
        unordered_map<char,int> delta1(const unordered_set<char>& alphabet, const string& pattern) {
            int n = pattern.length();
            unordered_map<char, int> m;
            for(auto& c: alphabet) {
                m[c] = n;
            }
            for(int i = 0 ; i < n - 1 ; ++i) {
                m[pattern[i]] = n - 1 - i;
            }
            return m;
        }

        bool isPrefix(const string& s, int pos) {
            int n = s.length();
            int sufflen = n - pos;

            for(int i = 0 ; i < sufflen ; ++i) {
                if(s[i] != s[n - pos + i]) return false;
            }
            return true;
        }

        vector<int> suffixes(const string& s) {
            int f = 0, g = 0, i = 0, n = s.length();
            vector<int> suff(n, 0);

            suff[n - 1] = n;
            g = n - 1;
            for (i = n - 2; i >= 0; --i) {
                if (i > g && suff[i + n - 1 - f] < i - g)
                    suff[i] = suff[i + n - 1 - f];
                else {
                    if (i < g) g = i;
                    f = i;
                    while (g >= 0 && s[g] == s[g + n - 1 - f]) --g;
                    suff[i] = f - g;
                }
            }
            return suff;
        }

        vector<int> delta2(const string& s) {
            int n = s.length();
            vector<int> delta2(n, n), suff = suffixes(s);

            int j = 0;
            for(int i = n - 1 ; i >= 0 ; --i) {
                if(suff[i] == i + 1) {
                    // For suffixes that also a prefix of the word
                    for(; j < n - 1 - i; ++j) {
                        if(delta2[j] == n) {
                            // If not set
                            delta2[j] = n - 1 - i;
                        }
                    }
                }
            }
            for(int i = 0 ; i < n - 1 ; ++i) {
                delta2[n - 1 - suff[i]] = n - 1 - i;
            }

            return delta2;
        }
    public:

        int boyerMoore(const string& word, const string& pattern) {
            unordered_set<char> alph;
            for(auto& c : word) {
                alph.insert(c);
            }

            auto d1 = delta1(alph, pattern);
            auto d2 = delta2(pattern);

            cerr << "Delta 1: ";
            for(auto& [k, v]: d1) {
                cerr << k << " -> " << v << ", ";
            }
            cerr << "\n";

            cerr << "Delta 2: ";
            for(auto& shift: d2) {
                cerr << shift <<", ";
            }
            cerr << "\n";

            int n = word.length();
            int m = pattern.length();
            if (n == 0) return 0;
            if(m > n) return 0;

            int j = 0, i = 0;
            while (j <= n - m) {
                for (i = m - 1; i >= 0 && pattern[i] == word[i + j]; --i);
                if (i < 0) {
                    cerr << "Match at: " << j << "\n";
                    j += d2[0];
                }
                else
                    j += max(d2[i], d1[word[i + j]] - (m - 1 - i));
            }
            return 0;
        }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        string word = "", pattern = "";
        cin >> word >> pattern;

        int res = Solution().boyerMoore(word, pattern);

        printf("%d\n", res);
    }

    return 0;
}
