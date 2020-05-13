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
        string removeKdigits(string num, int k) {
            int num_s = num.size();
            if (num_s == 0) {
                return num;
            }
            if (num_s <= k) {
                return "0";
            }

            int rem = 0;
            stack<int> s;
            for(auto& c: num) {
                int n = (int)(c - '0');
                while((!s.empty() && rem < k) && s.top() >= n) {
                    s.pop();
                    ++rem;
                }
                if(!s.empty() || n != 0) {
                    s.emplace(n);
                }
            }

            string res;
            res.reserve(num_s - k);

            while(!s.empty()) {
                if(s.size() <= num_s - k) {
                    res.push_back((char)(s.top() + '0'));
                }
                s.pop();
            }

            reverse(res.begin(), res.end());
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

        string num;
        num.reserve(n);

        cin >> num;

        auto res = Solution().removeKdigits(num, k);
        cout << res << "\n";
    }

    return 0;
}
