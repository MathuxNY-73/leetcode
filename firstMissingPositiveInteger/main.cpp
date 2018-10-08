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
        nums.push_back(0);
        auto n = nums.size();

        for(auto it = nums.begin(); it != nums.end() ; ++it)
        {
            if(*it < 0 || *it >= n)
            {
                *it = 0;
            }
        }

        for(auto i = 0; i < n ; ++i)
        {
            nums[nums[i] % n] += n;
        }

        for(auto i = 0; i < n ; ++i)
        {
            if(nums[i]/n == 0)
            {
                return i;
            }
        }

        return n;
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