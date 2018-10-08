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
public:
    int firstMissingPositive(vector<int>& nums) {
        // This should disappear if we want linear time
        sort(nums.begin(), nums.end());
        
        auto res = 1;
        
        for(auto x: nums)
        {
            if(x > 0 && x == res)
            {
                ++res;
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
    int t = 0;
    fastscan(t);

    wl(t)
    {
        int n = 0;
        fastscan(n);

        auto nums = vector<int>(n);

        int i;
        fl(i, 0, n)
        {
            fastscan(nums[i]);
        }

        auto res = Solution().firstMissingPositive(nums);

        printf("%d\n", res);
    }

    return 0;
}