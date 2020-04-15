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

using namespace std;

static int fast_stream = []() {
                             ios::sync_with_stdio(false);
                             cin.tie(nullptr);
                             cout.tie(nullptr);
                             return 0;
                         }();

class Solution {
public:
        bool backspaceCompare(string S, string T) {

            int ptr_s = 0;
            for(int i = 0 ; i < S.size(); ++i) {
                if(S[i] == '#') {
                    ptr_s = max(ptr_s - 1, 0);
                }
                else{
                    S[ptr_s] = S[i];
                    ++ptr_s;
                }
            }

            int ptr_t = 0;
            for(int i = 0 ; i < T.size(); ++i) {
                if(T[i] == '#') {
                    ptr_t = max(ptr_t - 1, 0);
                }
                else{
                    T[ptr_t] = T[i];
                    ++ptr_t;
                }
            }

            /*
            printf("ptr_s=%d, ", ptr_s);
            for(int i = 0 ; i < ptr_s ; ++i) {
                printf("%c", S[i]);
            }
            printf(", ptr_t=%d, ", ptr_t);
            for(int i = 0 ; i < ptr_t ; ++i) {
                printf("%c", T[i]);
            }
            printf("\n");
            */

            if(ptr_s != ptr_t) {
                return false;
            }

            for(int i = 0 ; i < ptr_s ; ++i) {
                if(S[i] != T[i]) {
                    return false;
                }
            }

            return true;
        }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0, m = 0;
        cin >> n >> m;

        string S, T;

        cin >> S >> T;

        bool res = Solution().backspaceCompare(S, T);

        printf("%s\n", res ? "true" : "false");
    }

    return 0;
}
