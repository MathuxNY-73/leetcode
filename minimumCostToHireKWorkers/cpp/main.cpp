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
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        auto ratios = vector<pair<int, int>>(quality.size());
        auto q = priority_queue<int, vector<int>, less<int>>();
        auto sum = 0;
        double res = 9999999999;

        for(auto i = 0; i < quality.size() ; ++i)
        {
            ratios[i] = make_pair(quality[i], wage[i]);
        }

        sort(ratios.begin(), ratios.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            return ((double)a.second/(double)a.first) < ((double)b.second/(double)b.first);
        });

        //print(ratios);
        for(auto&& it: ratios)
        {
            //cout << "it.first:" << it.first << " it.second:" << it.second << endl;
            q.push(it.first);
            sum += it.first;
            if(q.size() > K)
            {
                sum -= q.top();
                q.pop();
            }
            if(q.size() == K)
            {
                res = min(res, sum * ((double)it.second/(double)it.first));
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
        auto w = vector<int>(n);

        int i;
        fl(i,0,n)
        {
                fastscan(q[i]);
        }

        fl(i,0,n)
        {
                fastscan(w[i]);
        }

        auto result = Solution().mincostToHireWorkers(q, w, k);

        printf("%f", result);

        printf("\n");
    }

    return 0;
}