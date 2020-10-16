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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;

        int l = 0, h = n * m;

        while(l < h) {
            int mid = l + ((h - l) >> 1);
            int x = mid / m, y = mid % m;

            if(matrix[x][y] >= target) h = mid;
            else l = mid + 1;
        }

        int x = l / m, y = l % m;
        return l != n * m && matrix[x][y] == target;
    }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, m = 0;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m, 0));

        for(auto& r: matrix) {
            for(auto& c: r) {
                cin >> c;
            }
        }

        int target = 0;
        cin >> target;

        auto res = Solution().searchMatrix(matrix, target);

        cout << res << "\n";
    }

    return 0;
}