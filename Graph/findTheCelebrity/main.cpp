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

class API {
    private:
        bool mat[SIZE][SIZE];
    public:

        API(bool (&adj)[SIZE][SIZE]) {
            for(int i = 0 ; i < SIZE ; ++i) {
                for(int j = 0 ; j < SIZE ; ++j) {
                    mat[i][j] = adj[i][j];
                }
            }
        }

        bool knows(int a, int b) {
            return mat[a][b];
        }
};

class Solution {
    private:
        API api;
    public:
        Solution(API api): api(api) {}

        int findCelebrity(int n) {
            int candidate = 0;
            for(int i = 1; i < n ; ++i) {
                if (api.knows(candidate, i)) {
                    candidate = i;
                }
            }

            for(int i = 0; i < n ; ++i) {
                if(!api.knows(i, candidate)) {
                    return -1;
                }
            }

            return candidate;
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

        bool adj[SIZE][SIZE];
        memset(adj, 0, sizeof(bool) * SIZE * SIZE);

        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < n ; ++j) {
                int x = 0;
                fastscan(x);
                adj[i][j] = x == 1;
            }
        }

        API api(adj);

        int res = Solution(api).findCelebrity(n);
        printf("%d\n", res);
    }

    return 0;
}
