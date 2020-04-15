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

#define SIZE 4 * 50000

using namespace std;

static int fast_stream = []() {
                             ios::sync_with_stdio(false);
                             cin.tie(nullptr);
                             cout.tie(nullptr);
                             return 0;
                         }();

class Solution {
    public:
        string stringShift(string s, const vector<vector<int>>& shift) const {
            int n = s.size();
            if (n == 0) {
                return s;
            }

            int cursor = 0;
            for(auto& s: shift) {
                cursor += (s[0] ? - s[1] : s[1]);
            }

            string res;
            res.reserve(n);

            cursor %= n;
            int start = cursor < 0 ? cursor + n : cursor;

            bool cycle = false;
            for(int i = start ; !cycle || i != start ; i = (i + 1) % n) {
                cycle = i ? cycle : !cycle;
                res.push_back(s[i]);
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
        int n=0, k = 0;
        cin >> n >> k;

        string s;
        s.reserve(n);
        cin >> s;

        vector<vector<int>> shift(k, vector<int>(2, 0));

        for(int i = 0 ; i < k ; ++i) {
            cin >> shift[i][0] >> shift[i][1];
        }

        auto res = Solution().stringShift(s, shift);
        printf("%s\n", res.c_str());
    }

    return 0;
}
