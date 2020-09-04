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
        vector<int> partitionLabels(string S) {
            int n = S.length();
            if(n == 0) return {};

            unordered_map<char, int> l;

            for(int i = 0 ; i < n ; ++i) l[S[i]] = i;

            vector<int> res;
            int i = 0, j = 0;
            while(i < n) {
                j = l[S[i]];
                int k = i;
                while(k < n && k < j) j = max(l[S[k++]], j);

                res.push_back(k - i + 1);
                i = j + 1;
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
        int n=0;
        cin >> n;

        string word;
        word.reserve(n);
        cin >> word;

        auto res = Solution().partitionLabels(word);

        for(auto& p: res) {
            cout << p << ", ";
        }
        cout << "\n";
    }

    return 0;
}
