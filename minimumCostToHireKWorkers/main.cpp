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
        auto sorted_quality = vector<pair<int, int>>(quality.size());
        auto wages = vector<double>(K);
        auto is_prev_min = vector<bool>(K);
        
        for(auto i = 0; i < quality.size() ; ++i)
        {
            sorted_quality[i] = make_pair(quality[i], i);
        }
        
        sort(sorted_quality.begin(), sorted_quality.end(), [&wage](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            return a.first == b.first ? 
                wage[a.second] ==  wage[b.second] ?
                    a.second < b.second : wage[a.second] < wage[b.second] : a.first < b.first;
        });
        
        print(sorted_quality);
        
        auto min_diff = 9999999;
        auto min_idx = 0;
        auto i = 0;
        for(auto it = sorted_quality.cbegin(); it != sorted_quality.cend() - K + 1 ; ++it, ++i)
        {

            auto max_min_w = max_element(it, it + K - 1, [&wage](const pair<int, int>& a, const pair<int, int>& b) -> bool {
               return wage[a.second] < wage[b.second]; 
            });

            cout << "Hello 1 i=" << i << endl;
            //auto r_min = (double)max_min_w->first / (double)it->first;
            auto r_max = (double)(it+K-1)->first / (double)max_min_w->first;
            
            cout << "Hello 2 i=" << i << endl;
            auto diff = (r_max * (double)wage[max_min_w->second]);
            cout << "Hello 4 diff=" << diff << endl;
            if(diff < min_diff)
            {
                min_diff = diff;
                min_idx = i;
            }
        }

        printf("%d\n", min_idx);
        
        is_prev_min[0] = true;
        wages[0] = wage[sorted_quality[min_idx].second];
        for(auto i = min_idx + 1 , j = 1; i < min_idx + K; ++i, ++j)
        {
            cout << "Hello 3 i=" << i << endl;
            auto r = (double)sorted_quality[i].first / (double)sorted_quality[i-1].first;
            auto idx = sorted_quality[i].second;
            wages[j] = wages[j-1] * r;
            if(wages[j] < wage[idx])
            {
                wages[j] = wage[idx];
                wages[j-1] = wages[j] / r;
                is_prev_min[j-1] = wages[j-1] == wage[sorted_quality[i-1].second];
            }
            else if(wages[j] > wage[idx] && !is_prev_min[j-1])
            {
                wages[j-1] = wage[sorted_quality[i-1].second];
                wages[j] = wages[j-1] * r;
                is_prev_min[j-1] = true;
            }
            
            is_prev_min[j] = wages[j] == wage[idx] || is_prev_min[j-1];
        }

        print(wages);
        
        for(int i = min_idx + K - 2, j = K - 2 ; i > min_idx ; --i, --j)
        {
            if(!is_prev_min[j])
            {
                auto r = (double)sorted_quality[i].first / (double)sorted_quality[i-1].first;
                wages[j-1] = wages[j] / r;
                is_prev_min[j-1] = wages[j-1] == wage[sorted_quality[i-1].second];
            }
        }
        
        auto res = accumulate(wages.cbegin(), wages.cend(), (double)0);
        
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