#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <stack>
#include <array>

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

        int imin = 0, imax = m;
        double res = 0;
        for(;imin <= imax;)
        {
            int i = ceil((imax + imin) / 2.0);
            int j = floor((m+n+1) / 2.0) - i;

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
                if((m+n) % 2 == 1)
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

inline void fastscan(int& number)
{
    //variable to indicate sign of input number
    bool negative = false;
    int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar_unlocked();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar_unlocked();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

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