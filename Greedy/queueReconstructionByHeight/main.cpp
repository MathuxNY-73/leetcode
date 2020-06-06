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
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

            stable_sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b)
            {
                return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
            });

            vector<vector<int>> res(people.size(), vector<int>(2, -1));

            for(auto& x: people) {
                int cnt = -1, i = 0;
                while(cnt < x[1]) {
                    if(res[i][1] == -1) {
                        ++cnt;
                    }
                    ++i;
                }
                --i;
                res[i][0] = x[0];
                res[i][1] = x[1];
            }

            return res;
        }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0;
        fastscan(n);

        vector<vector<int>> people(n, vector<int>(2, 0));

        for(auto& p: people) {
            fastscan(p[0]);
            fastscan(p[1]);
        }

        auto res = Solution().reconstructQueue(people);
        for(auto& p: res) {
            cout << p[0] << " " << p[1] << "\n";
        }
    }

    return 0;
}
