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
        vector<int> sequentialDigits(int low, int high) {
            vector<int> res;
            queue<int> q;

            for(int i = 1 ; i < 10 ; ++i) q.push(i);

            while(!q.empty()) {
                int cur = q.front(); q.pop();
                if(cur > high) continue;
                if(cur >= low && cur <= high) res.push_back(cur);

                int next = (cur % 10) + 1;
                if(next < 10) q.push(cur * 10 + next);
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
        int low=0, high=0;
        cin >> low >> high;

        auto res = Solution().sequentialDigits(low, high);
        for(auto& el: res) {
            cout << el << " ";
        }
        cout << "\n";
    }

    return 0;
}
