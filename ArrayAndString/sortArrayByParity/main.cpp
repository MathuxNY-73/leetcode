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

        vector<int> sortArrayByParity(vector<int>& A) {
            int l = 0, r = A.size() - 1;

            while(l < r) {
                while(l < r && !(A[l] & 1)) ++l;
                while(l < r && (A[r] & 1)) --r;
                swap(A[l], A[r]);
            }
            return A;
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

        vector<int> A(n, 0);

        for(auto& e: A) {
            cin >> e;
        }

        vector<int> res = Solution().sortArrayByParity(A);

        for(auto& e: res) {
            cout << e << " ";
        }
        cout << "\n";
    }

    return 0;
}
