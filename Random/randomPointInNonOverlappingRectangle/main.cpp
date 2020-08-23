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
#define min(a,b) a < b ? a : b
#define max(a,b) a < b ? b : a
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

static int fast_stream = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    private:
        vector<int> psum;
        const vector<vector<int>>& rects;
        mt19937 gen;
        uniform_int_distribution<int> dis;
    public:
        Solution(const vector<vector<int>>& rects): psum(vector<int>(rects.size(), 0)), rects(rects), gen(mt19937(random_device()())) {
            int ptr = 0, sum = 0;
            for(auto& r: rects) {
                int area = abs(r[2] - r[0] + 1) * abs(r[3] - r[1] + 1);
                sum += area;
                psum[ptr++] = sum;
            }
            dis = uniform_int_distribution<int>(0,sum - 1);
        }


        vector<int> pick() {
            int pick = dis(gen);

            int l = 0, r = psum.size() - 1;
            while(l < r) {
                int m = l + ((r - l) >> 1);
                if(pick >= psum[m]) l = m + 1;
                else r = m;
            }

            int length = abs(rects[l][2] - rects[l][0] + 1);
            int width = abs(rects[l][3] - rects[l][1] + 1);
            int base = psum[l] - length * width;

            return {rects[l][0] + ((pick - base) % length) , rects[l][1] + ((pick - base) / length)};
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

        vector<vector<int>> rects(n, vector<int>(4, 0));

        for(auto& r: rects) {
            for(auto& c: r) {
                cin >> c;
            }
        }

        Solution s(rects);

        while(m--) {
            auto picked = s.pick();
            for(auto& c: picked) {
                cout << c << " ";
            }
            cout << "\n";
        }

    }

    return 0;
}
