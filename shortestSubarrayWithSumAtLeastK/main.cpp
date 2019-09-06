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

    static int shortestSubarray(const vector<int>& A, int K) {
        auto a_length = A.size();
        auto min_length = a_length;
        auto found = false;

        for(auto i = 0 ; i < a_length ; ++i) {
            auto cum = 0;
            for(auto j = i ; j < min(i + min_length, a_length) ; ++j) {
                if(A[j] >= K) {
                    return 1;
                }
                else {
                    cum += A[j];
                    if(cum >= K) {
                        found = true;
                        min_length = j - i + 1;
                        //cout << "min_length: " << min_length << "\n";
                        break;
                    }
                }
            }
        }
        return found ? min_length : -1;
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
