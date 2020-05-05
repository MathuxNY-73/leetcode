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
        int firstUniqChar(string s) {
            int freq[26];
            memset(freq, 0, sizeof(int) * 26);

            for(auto& c: s) {
                ++freq[c - 'a'];
            }

            for(int i = 0 ; i < s.size() ; ++i) {
                if (freq[s[i] - 'a'] == 1) {
                    return i;
                }
            }

            return -1;
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

        cout << Solution().firstUniqChar(s) << "\n";
    }

    return 0;
}
