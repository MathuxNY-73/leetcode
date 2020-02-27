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
        string longestPalindrome(string s) const {
            if (s.size() == 0) {
                return "";
            }

            bool even = false;
            int max_idx = 0, length = 1;

            for(int i = 0 ; i < s.size() ; ++i) {
                int l_odd = exploreFromTheCenterOdd(s, i);
                int l_even = exploreFromTheCenterEven(s, i);
                fprintf(stderr, "Odd is : %d\n", l_odd);
                fprintf(stderr, "Even is : %d\n", l_even);
                if(l_odd > length) {
                    max_idx = i;
                    even = false;
                    length = l_odd;
                }
                if(l_even > length) {
                    max_idx = i;
                    even = true;
                    length = l_even;
                }
            }

            return s.substr(max_idx - length / 2, length);
        }

        int exploreFromTheCenterOdd(string s, int i) const {
            int res = 1;
            for(int k = 1 ; k < s.size() / 2 + 1; ++k) {
                if(i - k < 0 || i + k >= s.size()) break;
                if(s[i-k] != s[i + k]) break;
                res += 2;
            }
            return res;
        }

        int exploreFromTheCenterEven(string s, int i) const {
            int res = 0;
            for(int k = 0 ; k < s.size() / 2 + 1; ++k) {
                if(i - k - 1 < 0 || i + k >= s.size()) break;
                if(s[i - k - 1] != s[i+k]) break;
                res += 2;
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

        char* buffer = new char[n+1];
        memset(buffer, '\0', sizeof(char) * (n+1));
        fastscan_char_w((char (&)[])(*buffer), n+1);
        for(int i = 0; i <= n ; ++i) {
            fprintf(stderr, "%c: %d", buffer[i], (int)buffer[i]);
        }
        fprintf(stderr, "\n");
        fprintf(stderr, "%s\n", buffer);
        auto res = Solution().longestPalindrome(buffer);
        printf("%s\n", res.c_str());
        delete[] buffer;
    }

    return 0;
}
