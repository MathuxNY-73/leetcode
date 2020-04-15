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
    static const map<int, const vector<char>> keyboard;

public:
   vector<string> letterCombinations(string digits) {
       auto res = vector<string>();

        if(digits.empty())
        {
            return res;
        }

        auto q = queue<string>();
        q.push("");
        for(auto i = 0 ; i < digits.size(); ++i)
        {
            while(q.front().size() == i)
            {
                auto cur = q.front();
                q.pop();
                auto chars = (*keyboard.find(digits[i] - '0')).second;

                for(auto x: chars)
                {
                    q.push(cur+x);
                }
            }
        }

        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};

const map<int, const vector<char>> Solution::keyboard = {
        {2 , {'a', 'b', 'c'}},
        {3 , {'d', 'e', 'f'}},
        {4 , {'g', 'h', 'i'}},
        {5 , {'j', 'k', 'l'}},
        {6 , {'m', 'n', 'o'}},
        {7 , {'p', 'q', 'r', 's'}},
        {8 , {'t', 'u', 'v'}},
        {9 , {'w', 'x', 'y', 'z'}}
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

        //auto result = Solution().findMedianSortedArrays(q, w);

        //printf("%f", result);

        printf("\n");
    }

    return 0;
}