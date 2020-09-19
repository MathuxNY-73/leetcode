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
#include <limits>
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

class Solution {
    public:
        bool isRobotBounded(string instructions) {
            int x = 0, y = 0, dir = 0;

            for(auto& c: instructions) {
                if(c == 'G') {
                    switch (dir) {
                        case 0:
                            ++y; break;
                        case 1:
                            ++x; break;
                        case 2:
                            --y; break;
                        case 3:
                            --x; break;
                    }
                }
                else {
                    dir += ((c == 'R' ? 1 : -1) + 4);
                    dir %= 4;
                }
            }

            return (x == 0 && y == 0) || dir != 0;
        }
};

int main()
{
    int t = 0;
    cin >> t;

    wl(t)
    {
        int n=0;
        cin >> n;

        string str;
        str.reserve(n);

        cin >> str;

        auto res = Solution().isRobotBounded(str);

        cout << (res ? "True" : "False") << "\n";
    }

    return 0;
}
