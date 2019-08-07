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

class Solution {
private:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    std::map<int,int> m;
    int bound;
public:
    Solution(int N, vector<int>& blacklist): gen(mt19937(random_device()())), dis(uniform_int_distribution<int>(0,N - 1 - blacklist.size())), bound(N-blacklist.size()) {
        sort(blacklist.begin(), blacklist.end());
        m = std::map<int, int>();
        int k = 0;
        while(k < blacklist.size() && blacklist[k] < bound) ++k;

        auto whitelist = vector<int>(k, 0);
        for(int i = bound, j = k, l = 0; i < N && l < k ; ++i, ++l) {
            while(j < blacklist.size() && blacklist[j] == i) ++i,++j;
            whitelist[l] = i;
        }

        printf("Whitelist: ");
        for(auto& w: whitelist) {
            printf("%d ", w);
        }
        printf("\n");

        for(int i = 0 ; i < k ; ++i) {
            m[blacklist[i]] = whitelist[i];
        }

        printf("Map: ");
        for(auto&& [f,s]: m) {
            printf("%d -> %d ", f,s);
        }
        printf("\n");

        srand(time(NULL));
    }

    int pick() {
        int picked = dis(gen);
        //while (picked >= bound) {
        //    picked = rand() / ((RAND_MAX + 1u) / bound);
        //}
        return m.find(picked) != m.cend() ? m[picked] : picked;
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
        int nb_blacklist = 0;
        fastscan(nb_blacklist);
        auto blacklist = vector<int>(nb_blacklist, 0);

        int i;
        fl(i, 0, nb_blacklist){
            fastscan(blacklist[i]);
        }

        auto rand_gen = Solution(n, blacklist);

        int nb_pick = 0;
        fastscan(nb_pick);

        printf("N = %d, nb_blacklist: %d, nb_pick: %d\n", n, nb_blacklist, nb_pick);
        for(auto& b: blacklist) {
            printf("%d ", b);
        }
        printf("\n");
        wl(nb_pick) {
            auto res = rand_gen.pick();
            printf("%d ", res);
        }
        puts("");
    }

    return 0;
}
