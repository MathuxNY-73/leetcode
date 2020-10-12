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
    int findMinArrowShots(vector<vector<int>>& points) const {
        int n = points.size();
        if(n == 0) return 0;

        auto sorter = [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        };

        sort(points.begin(), points.end(), sorter);

        int end = points[0][1], cnt = 1;
        for(int i = 1; i < points.size() ; ++i) {
            if (points[i][0] <= end) {
                end = min(points[i][1], end);
            }
            else {
                end = points[i][1];
                ++cnt;
            }
        }

        return cnt;
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

        vector<vector<int>> points(n, vector<int>(2, 0));

        for(auto& p: points) {
            cin >> p[0] >> p[1];
        }

        auto res = Solution().findMinArrowShots(points);

        cout << res << "\n";
    }

    return 0;
}
