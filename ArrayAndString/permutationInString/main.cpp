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
    private:
        bool check_empty(const array<int, 26>& arr) const {
            for(auto& f: arr) {
                if (f) {
                    return false;
                }
            }
            return true;
        }
    public:
        bool checkInclusionOpt(string s1, string s2) const {
            if (s2.size() == 0) {
                return s1.size() == 0;
            }
            else if (s1.size() > s2.size()) {
                return false;
            }

            array<int, 26> freq = {0};
            for(int i = 0 ; i < s1.size() ; ++i) {
                --freq[s1[i] - 'a'];
                ++freq[s2[i] - 'a'];
            }

            for(int i = s1.size() ; i < s2.size() ; ++i) {
                if(check_empty(freq)) {
                    return true;
                }
                ++freq[s2[i] - 'a'];
                --freq[s2[i - s1.size()] - 'a'];
            }

            return check_empty(freq);
        }


        bool checkInclusion(string s1, string s2) const {
            if (s2.size() == 0) {
                return s1.size() == 0;
            }
            else if (s2.size() < s1.size()) {
                return false;
            }

            array<int, 26> freq = {0};
            for(auto& c: s1) {
                ++freq[c - 'a'];
            }

            array<int, 26> freq_orig = freq;
            for(int i = 0 ; i < s2.size() ; ++i) {
                for(int j = 0 ; (j < s1.size() &&
                                 j + i < s2.size()) &&
                                 freq[s2[j+i] - 'a'] ; ++j) {
                    --freq[s2[j + i] - 'a'];
                }
                if(check_empty(freq)) {
                    return true;
                }
                else{
                    freq = freq_orig;
                }

            }

            return false;
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

        string s1, s2;
        s1.reserve(n);
        s2.reserve(m);

        cin >> s1;
        cin >> s2;

        cout << Solution().checkInclusionOpt(s1, s2) << "\n";
    }

    return 0;
}
