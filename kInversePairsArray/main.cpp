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
#define min(a,b) a < b ? a : b
#define max(a,b) a < b ? b : a
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

class Solution {
private:
    void empty_stack(queue<int>& q) const {
        while(!q.empty())
        {
            q.pop();
        }
    }
public:
    int kInversePairs(int n, int k) {
        if(n == 0 || n == 1)
        {
            return k ? 0 : 1;
        }

        auto base = pow(10,9) + 7;
        auto dp = vector<int>(k+1, 0);
        auto sum = 0;

        dp[0] = 1;

        for(int i = 2 ; i <= n ; ++i)
        {
            sum = 1;
            auto q = queue<int>();
            q.push(1);
            for(int j = 1 ; j <= k ; ++j)
            {
                sum = fmodl(fmodl(sum, base) + fmodl(dp[j],base), base);
                q.push(fmodl(dp[j], base));
                if(q.size() > i)
                {
                    sum -= q.front();
                    sum = sum < 0 ? base + sum : sum;
                    q.pop();
                }
                dp[j] = sum;
            }
        }

        return dp[k];
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

static inline int fastscan_string_w(char (&str)[], int buffer_size)
{
    char c;
    int size_of_str = 0;

    // extract current character from buffer
    c = getchar_unlocked();

    // Keep on extracting characters if they are not
    // space, carriage return or end of string
    for (; c != ' '
             && c != '\n'
             && c != '\0';
         c=getchar_unlocked(),++size_of_str)
        {
            if(size_of_str > buffer_size)
                exit(-1);
            str[size_of_str] = c;
        }

    return  size_of_str;
}

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0,k=0;
        fastscan(n);
        fastscan(k);
        auto res = Solution().kInversePairs(n,k);
        printf("%d\n", res);
    }

    return 0;
}
