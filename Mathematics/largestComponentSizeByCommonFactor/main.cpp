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

    private:
        unordered_map<int,pair<int, int>> par;

        int find(int key) {
            if(par.find(key) == par.cend()) {
                par[key] = make_pair(key, 1);
                return key;
            }
            if(par[key].first == key) return key;
            return par[key].first = find(par[key].first);
        }

        void union_set(int a, int b) {
            int pa = find(a);
            int pb = find(b);
            //cout << "Joining " << pa << " (size=" << par[pa].second << ") and " << pb << " (size="<<par[pb].second<< ") for " << a << " and " << b <<"\n";
            if(pa != pb) {
                int sa = par[pa].second;
                int sb = par[pb].second;

                if(sa < sb) {
                    par[pa].first = pb;
                    par[pb].second += par[pa].second;
                }
                else {
                    par[pb].first = pa;
                    par[pa].second += par[pb].second;
                }
            }
        }
        vector<int> primes;
public:

    Solution() {
        vector<bool> sieve(321, true);
        sieve[0] = sieve[1] = false;
        for(int i = 2 ; i <= 320 ; ++i) {
            if(sieve[i]) {
                for(int j = i * i ; j <= 320 ; j += i) sieve[j] = false;
            }
        }
        for(int i = 0; i <= 320 ; ++i) {
            if(sieve[i]) primes.push_back(i);
        }

    }

    int largestComponentSize(vector<int>& A) {
        for(auto& num: A) {
            int tmp = num;
            int i = 0;
            while(tmp >= primes[i] * primes[i]) {
                if(tmp % primes[i] == 0) {
                    union_set(primes[i], num);
                    tmp /= primes[i];
                }
                else {
                    ++i;
                }
            }
            union_set(tmp, num);
        }

        int max_s = 0;
        unordered_map<int, int> cnt;
        for(auto& num: A) {
            //cout << "k=" << k << " par=" << v.second << "\n";
            int p = find(num);
            if (cnt.find(p) == cnt.cend()) cnt[p] = 0;
            max_s = max(max_s , ++cnt[p]);
        }

        return max_s;

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

        vector<int> nums(n, 0);

        for(auto& num: nums) fastscan(num);

        auto res = Solution().largestComponentSize(nums);
        printf("%d\n", res);
    }

    return 0;
}
