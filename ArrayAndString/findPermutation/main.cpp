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

        vector<int> findPermutation(string s) {
            int num = 1;

            vector<int> res(s.size() + 1, 0);

            int i = -1, r = 0;
            while(i < (int)s.size()) {
                int c = 1;
                while(i + c < s.size() && s[i + c] == 'D') ++c;

                int t = c;
                while(t > 0) res[r++] = (num + (--t));

                num += c;
                i += c;
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
        int n=0;
        cin >> n;

        string s;
        s.reserve(n);

        cin >> s;

        vector<int> res = Solution().findPermutation(s);

        for(auto& e: res) {
            cout << e << " ";
        }
        cout << "\n";
    }

    return 0;
}
