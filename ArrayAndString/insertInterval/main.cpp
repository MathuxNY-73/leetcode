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

void print_vector(vector<vector<int>>& v) {
    printf("[");
    for(auto& inter: v) {
        printf("[");
        for(auto& el: inter) {
            printf("%d,", el);
        }
        printf("]");
    }
    printf("]\n");
}



class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto res = vector<vector<int>>();
        auto start = newInterval[0], end = newInterval[1];
        int i = 0;
        int n = intervals.size();

        for(;i < n && intervals[i][1] < start; ++i) {
            res.emplace_back(intervals[i]);
        }

        if(i == n) {
            res.emplace_back(newInterval);
            return res;
        }
        else if (intervals[i][0] > end) {
            res.emplace_back(newInterval);
        }
        else {
            auto newV = vector<int>(2);
            newV[0] = min(intervals[i][0], start);
            newV[1] = max(intervals[i][1], end);

            for(++i; i < n && intervals[i][0] <= newV[1];++i) {
                newV[1] = intervals[i][1] > newV[1] ? intervals[i][1]: newV[1];
            }

            res.emplace_back(newV);
        }

        for(;i < n ; ++i) {
            res.emplace_back(intervals[i]);
        }

        return res;
    }
};

static inline void fastscan(int& number)
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
             && c != '\0'
             && c != EOF;
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
        int n=0;
        fastscan(n);
        auto intervals = vector<vector<int>>(n-1, vector<int>(2, 0));
        for(int i = 0 ; i < n-1 ; ++i) {
            fastscan(intervals[i][0]);
            fastscan(intervals[i][1]);
        }
        auto newInterval = vector<int>(2,0);
        fastscan(newInterval[0]);
        fastscan(newInterval[1]);

        print_vector(intervals);
        printf("newInterval: [%d, %d]\n", newInterval[0], newInterval[1]);
        auto res = Solution().insert(intervals, newInterval);
        print_vector(res);

    }

    return 0;
}
