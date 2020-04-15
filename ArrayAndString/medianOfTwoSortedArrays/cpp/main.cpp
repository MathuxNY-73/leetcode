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

class Solution {
    private:
    void print(const vector<pair<int, int>>& a) const {
        for(auto it = a.cbegin(); it != a.cend() ; ++it)
        {
            printf("(%d, %d) ", it->first, it->second);
        }
        printf("\n");
    }

    void print(const vector<double>& a) const {
        for(auto it = a.cbegin(); it != a.cend() ; ++it)
        {
            printf("%f ", *it);
        }
        printf("\n");
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto a = nums1.size() > nums2.size() ? nums2 : nums1;
        auto b = nums1.size() > nums2.size() ? nums1 : nums2;
        auto n = b.size();
        auto m = a.size();

        if (!m) {
            if(n & 1) {
                return b[n/2];
            }
            else {
                return (b[(n-1)/2] + b[n/2]) / 2.0;
            }
        }

        int imin = 0, imax = m;
        double res = 0;
        for(;imin <= imax;)
        {
            int i = (imax + imin) / 2;
            int j = (m+n+1) / 2 - i;

            //printf("i: %d\n", i);
            //printf("j: %d\n", j);

            //printf("imin: %d\n", imin);
            //printf("imax: %d\n", imax);
            if(i < imax && a[i] < b[j-1])
            {
                imin = i + 1;
            }
            else if(i > imin && a[i - 1] > b[j])
            {
                imax = i - 1;
            }
            else
            {
                auto minRight = 0;
                if(i == m)
                {
                    minRight = b[j];
                }
                else if(j == n)
                {
                    minRight = a[i];
                }
                else
                {
                    minRight = min(a[i], b[j]);
                }

                auto maxLeft = 0;
                if(i == 0)
                {
                    maxLeft = b[j-1];
                }
                else if(j == 0)
                {
                    maxLeft = a[i-1];
                }
                else
                {
                    maxLeft = max(a[i-1], b[j-1]);
                }
                if((m+n) & 1)
                {
                    res = maxLeft;
                }
                else
                {
                    res = (minRight + maxLeft) / 2.0;
                }
                break;
            }
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
        int n, k;
        fastscan(n);
        fastscan(k);

        auto q = vector<int>(n);
        auto w = vector<int>(k);

        int i;
        fl(i,0,n)
        {
                fastscan(q[i]);
        }

        fl(i,0,k)
        {
                fastscan(w[i]);
        }

        auto result = Solution().findMedianSortedArrays(q, w);

        printf("%f", result);

        printf("\n");
    }

    return 0;
}
