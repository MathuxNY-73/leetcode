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
        int permutation = n*(n - 1) / 2;
        if (k > permutation)return 0;
        if(n == 0 || n == 1)
        {
            return k ? 0 : 1;
        }

        int base = pow(10,9) + 7;
        int* dp = new int[k+1];
        memset(dp, 0, sizeof(int) * (k+1));

        dp[0] = 1;

        for(int i = 2 ; i <= n ; ++i)
        {
            int* temp = new int[k+1];
            memset(temp, 0, sizeof(int) * (k+1));
            temp[0] = 1;

            for(int j = 1 ; j <= k ; ++j)
            {
                temp[j] = (dp[j] + base - (j >= i ? dp[j - i] : 0)) % base;
                temp[j] = (temp[j] + temp[j-1]) % base;
            }
            delete[] dp;
            dp = temp;
        }

        return dp[k] < 0 ? base - dp[k] : dp[k];
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
