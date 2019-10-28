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
private:
    double vec_l2_norm(const vector<int>& vec) const {
        return sqrt(pow(vec[0],2) + pow(vec[1], 2));
    }

    struct PairHasher {
        size_t operator()(const vector<int>& k) const {
            return (hash<int>()(k[0]) ^ (hash<int>()(k[1]) << 1)) >> 1;
        }
    };

public:
    double minAreaFreeRect(const vector<vector<int>>& points) const {
        auto n = points.size();
        if(n == 0) {
            return 0;
        }

        auto s = unordered_set<vector<int>, PairHasher>();
        for(auto i = 0 ; i < n ; ++i) {
            s.insert(points[i]);
        }

        auto min_area = numeric_limits<double>::max();
        auto rec = false;

        for(auto i = 0 ; i < n ; ++i) {
            for(auto j = 0 ; j < n ; ++j) {
                if (i != j) {
                for(auto k = 0 ; k < n ; ++k) {
                    if(j != k && k != i) {
                        vector<int> vec_a = {points[j][0] - points[i][0], points[j][1] - points[i][1]};
                        vector<int> vec_b = {points[k][0] - points[i][0], points[k][1] - points[i][1]};
                        auto prod = vec_a[0] * vec_b[0] + vec_a[1] * vec_b[1];
                        if(prod == 0) {
                            // It is a right angle
                            vector<int> fourth_point = {vec_a[0] + vec_b[0] + points[i][0],
                                                 vec_a[1] + vec_b[1] + points[i][1]};
                            if(s.find(fourth_point) != s.cend()) {
                                rec = true;
                                auto area = vec_l2_norm(vec_a) * vec_l2_norm(vec_b);
                                if (area < min_area) {
                                    min_area = area;
                                }
                            }
                        }
                    }
                }
                }
            }
        }
        return rec ? min_area : 0;
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
        auto points = vector<vector<int>>(n, vector<int>(2, 0));

        int i;
        fl(i, 0, n){
            fastscan(points[i][0]);
            fastscan(points[i][1]);
        }

        auto res = Solution().minAreaFreeRect(points);
        printf("%f\n", res);
    }

    return 0;
}
