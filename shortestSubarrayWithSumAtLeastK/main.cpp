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

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

static const auto _____ = []()
                          {
                              ios::sync_with_stdio(false);
                              cin.tie(nullptr);
                              cout.tie(nullptr);
                              return nullptr;
                          }();

class Solution {
public:

    static int shortestSubarray(vector<int>& A, int K) {
        auto dq = deque<pair<int, int>>();
        auto a_length = A.size();
        auto min_length = a_length + 1;
        auto cum = 0;

        dq.push_back({0,-1});

        for(auto i = 0; i < a_length ; ++i) {
            cum += A[i];
            while(!dq.empty() && dq.back().first >= cum) {
                dq.pop_back();
            }
            while(!dq.empty() && cum - dq.front().first >= K) {
                auto diff = i - dq.front().second;
                min_length = diff < min_length ? diff : min_length;
                dq.pop_front();
            }
            dq.push_back(make_pair(cum, i));
        }
        return min_length >= a_length + 1 ? -1 : min_length;
    }
};

int main()
{
    int t;
    cin >> t;
    wl(t)
    {
        int n=0, k=0;
        cin >> n >> k;
        auto array = vector<int>(n, 0);

        int i;
        fl(i, 0, n){
            cin >> array[i];
        }

        auto res = Solution::shortestSubarray(array, k);
        cout << res << "\n";
    }

    return 0;
}
