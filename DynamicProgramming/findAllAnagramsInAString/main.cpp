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
        bool all_zeroes(const array<int, 26>& arr) const {
            for(auto& x: arr) {
                if (x) {
                    return false;
                }
            }
            return true;
        }
    public:
        vector<int> findAnagrams(const string& s, const string& p) {
            if(s.size() < p.size()) {
                return vector<int>(0);
            }

            array<int, 26> freq = {0};
            vector<int> res;

            for(int i = 0 ; i < p.size() ; ++i) {
                --freq[p[i] - 'a'];
                ++freq[s[i] - 'a'];
            }


            int i = p.size();
            for(; i < s.size() ; ++i) {
                if(all_zeroes(freq)) {
                    res.push_back(i - p.size());
                }
                ++freq[s[i] - 'a'];
                --freq[s[i - p.size()] - 'a'];
            }

            if(all_zeroes(freq)) {
                res.push_back(i - p.size());
            }

            res.shrink_to_fit();
            return res;

        }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, p_s =0;
        cin >> n;

        string s, p;
        s.reserve(n);

        cin >> s;
        cin >> p_s;

        p.reserve(p_s);
        cin >> p;

        auto res = Solution().findAnagrams(s, p);

        for(auto& x: res) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
