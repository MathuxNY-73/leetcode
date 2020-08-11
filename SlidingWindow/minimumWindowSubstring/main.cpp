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

        string minWindow(string s, string t) {
            unordered_map<char, int> freq, window;
            vector<pair<char, int>> fs;

            int req = 0;

            for(auto& c : t) {
                if(freq.find(c) == freq.cend()) {
                    freq.insert(make_pair(c, 0));
                    ++req;
                }
                ++freq[c];
            }

            for(int i = 0 ; i < s.size() ; ++i) {
                if(freq.find(s[i]) != freq.cend()) {
                    fs.push_back(make_pair(s[i], i));
                }
            }


            int l = 0, r = 0, found = 0;
            int min_l = 0, min_r = s.size();

            for(;r < fs.size(); ++r) {

                char cr = '\0';
                int idxr = 0;
                tie(cr, idxr) = fs[r];

                if(--freq[cr] >= 0) ++found;

                for(;l <= r && found == t.size();++l) {

                    char cl = '\0';
                    int idxl = 0;
                    tie(cl, idxl) = fs[l];

                    if (idxr - idxl < min_r - min_l) {
                        min_r = idxr;
                        min_l = idxl;
                    }


                    if(++freq[cl] > 0) --found;
                }
            }

            return min_r < s.size() ? s.substr(min_l, min_r - min_l + 1) : "";
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

        string s, p;
        s.reserve(n);
        p.reserve(m);

        cin >> s >> p;

        //cout << "s=" << s << " and p=" << p << "\n";

        auto res = Solution().minWindow(s, p);

        cout << res << "\n";
    }

    return 0;
}
