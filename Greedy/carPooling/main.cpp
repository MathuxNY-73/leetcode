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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        if(n == 0) return true;

        if(capacity == 0) return false;

        vector<pair<int, int>> cap;
        for(auto& t: trips) {
            cap.push_back(make_pair(t[1], -t[0]));
            cap.push_back(make_pair(t[2], t[0]));
        }

        sort(cap.begin(), cap.end(), [](const pair<int,int>& a, const pair<int, int>& b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });

        int cur = capacity;
        for(auto& t: cap) {
            cur += t.second;
            if(cur < 0) return false;
        }

        return true;
    }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, capacity = 0;
        cin >> n >> capacity;

        vector<vector<int>> trips(n, vector<int>(3, 0));

        for(auto& t: trips) {
            cin >> t[0] >> t[1] >> t[2];
        }

        auto res = Solution().carPooling(trips, capacity);
        cout << (res ? "True" : "False") << "\n";
    }

    return 0;
}
