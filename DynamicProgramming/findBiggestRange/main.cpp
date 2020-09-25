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
        vector<int> largestRange(vector<int>& array) {
            int n = array.size();
            if(n == 0) return {};

            unordered_set<int> s;
            for(auto& e: array) {
                s.insert(e);
            }

            vector<int> res(2, 0);
            for(auto& e: array) {
                if(res[0] <= e && e <= res[1]) continue;
                int l = e - 1, r = e + 1;
                while(s.find(r) != s.end()) ++r;
                while(s.find(l) != s.end()) --l;

                if(res[1] - res[0] <= r - l - 2) {
                    res[1] = r - 1;
                    res[0] = l + 1;
                }
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

        vector<int> array(n, 0);
        for(auto& e: array) {
            cin >> e;
        }

        auto res = Solution().largestRange(array);

        for(auto& x: res) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
