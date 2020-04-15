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
#include <stdexcept>

#define wl(n) while(n--)
#define min(a,b) a < b ? a : b
#define max(a,b) a < b ? b : a
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

class ModularInt {
private:
    int number;
    int module;
public:
    ModularInt(const int& i, const int& m): number(i % m), module(m) {}

    int getValue() const { return number; }
    int getModule() const { return module; }

    ModularInt operator +(const int& other) const {
        return ModularInt((number + (other % module)) % module, module);
    }

    ModularInt operator +(const ModularInt& other) const {
        return ModularInt((number + other.getValue()) % module, module);
    }

    ModularInt operator -(const ModularInt& other) const {
        int res = number - other.getValue();
        return ModularInt(res < 0 ? module + res : res, module);
    }
};

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
        auto dp = vector<ModularInt>(k+1, ModularInt(0, base));

        dp[0] = ModularInt(1, base);

        for(int i = 2 ; i <= n ; ++i)
        {
            auto temp = vector<ModularInt>(k+1, ModularInt(0,base));
            temp[0] = ModularInt(1, base);
 
            for(int j = 1 ; j <= k ; ++j)
            {
                temp[j] = dp[j] - (j >= i ? dp[j - i] : ModularInt(0,base));
                temp[j] = temp[j] + temp[j-1];
            }
            dp = temp;
        }
        auto res = dp[k].getValue();
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
