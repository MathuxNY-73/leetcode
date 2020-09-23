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
        int canCompleteCircuit(const vector<int>& gas, const vector<int>& costs) {
            int n = gas.size();
            int m = costs.size();

            if(n != m) return -1;
            if(n == 0) return -1;

            int total = 0, tank = 0, cand = 0;
            for(int i = 0 ; i < n ;++i) {
                int diff = gas[i] - costs[i];
                total += diff;
                tank += diff;
                if(tank < 0) {
                    cand = i + 1;
                    tank = 0;
                }
            }

            if(total < 0) return -1;
            return cand % n;
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

        vector<int> gas(n, 0), costs(n, 0);
        for(auto& x: gas) {
            cin >> x;
        }
        for(auto& x: costs) {
            cin >> x;
        }

        auto res = Solution().canCompleteCircuit(gas, costs);
        cout << res << "\n";
    }

    return 0;
}
