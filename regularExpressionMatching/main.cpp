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
    typedef struct Result {
        Result(): isSet(false) {}

        bool match;
        bool isSet;
    } Result;
public:
    bool isMatch(string s, string p) {
        if(p.empty())
        {
            return s.empty();
        }
        else
        {
            auto m = !s.empty() && (s[0] == p[0] || p[0] == '.');
            if(p.size() >= 2 && p[1] == '*')
            {
                return (m && isMatch(s.substr(1), p)) || isMatch(s, p.substr(2));
            }
            else
            {
                return m && isMatch(s.substr(1), p.substr(1));
            }
        }
    }

    bool isMatchDpTd(string s, string p)
    {
        auto res = new Result*[s.size() + 1];
        for(int i = 0 ; i <= s.size() ; ++i)
        {
            res[i] = new Result[p.size() + 1];
        }

        auto match = memoize(0,0,res,s,p);

        for(int i = 0 ; i <= s.size() ; ++i)
        {
            delete[] res[i];
        }
        delete[] res;

        return match;
    }

    bool memoize(int i, int j, Result* res[], string s, string p)
    {
        if(res[i][j].isSet)
        {
            return res[i][j].match;
        }

        if(j == p.size())
        {
            return i == s.size();
        }

        auto m = i != s.size() && (s[i] == p[j] || p[j] == '.');
        if(j+2 <= p.size() && p[j+1] == '*')
        {
            res[i][j].match = (m && memoize(i + 1, j, res, s, p)) || memoize(i, j + 2, res, s, p);
            res[i][j].isSet = true;
        }
        else
        {
            res[i][j].match = m && memoize(i+1, j+1, res, s, p);
            res[i][j].isSet = true;
        }

        return res[i][j].match;
    }

    bool isMatchDpBu(string s, string p) {
        bool dp[s.size()+1][p.size()+1];

        for(auto i = 0 ; i <= s.size() ; ++i)
        {
            for(auto j = 0 ; j <= p.size() ; ++j)
            {
                dp[i][j] = false;
            }
        }

        dp[s.size()][p.size()] = true;


        for(int i = s.size() ; i >= 0 ; --i)
        {
            for(int j = p.size() - 1 ; j >= 0 ; --j)
            {
                auto m = i < s.size() && (s[i] == p[j] || p[j] == '.');
                if(j+1 < p.size() && p[j+1] == '*')
                {
                    dp[i][j] = (m && dp[i+1][j]) || dp[i][j+2];
                }
                else
                {
                    dp[i][j] = m && dp[i+1][j+1];
                }
            }
        }

        return dp[0][0];
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
        string s = "";
        cin >> s;
        string p = "";
        cin >> p;

        auto res = Solution().isMatchDpBu(s, p);
        cout << (res ? "true" : "false") << endl;
    }

    return 0;
}