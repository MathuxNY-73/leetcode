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

using namespace std;

class Solution {
    public:

string format(const vector<int>& d) const {
    string res;
    auto k = 0;
    for(auto i = 0; i < 5 ; ++i)
    {
        if(i == 2)
        {
            res.append(":");    
            continue;
        }
        res.append(to_string(d[k]));
        ++k;
    }
    return res;
}

string nextClosestTime(string time) {
   auto digits = vector<int>(4);
    auto digits_s = set<int>();
    auto k = 0;
    for(auto i = 0 ; i < 5 ; ++i)
    {
        if(i == 2)
        {
            continue;
        }
        auto d = (int)(time[i] - '0');
        digits[k] = d;
        if(digits_s.find(d) == digits_s.cend())
        {
            digits_s.insert(d);
        }
        ++k;
    }

    auto min = *(digits_s.cbegin());
    
    auto it = digits_s.find(digits[3]);
    if(++it != digits_s.cend())
    {
        digits[3] = *it;
        
        return format(digits);
    }

    it = digits_s.find(digits[2]);
    if(++it != digits_s.cend() && *it < 6)
    {
        digits[2] = *it;
        digits[3] = min;
        
        return format(digits);
    }

    it = digits_s.find(digits[1]);
    if(++it != digits_s.cend() && (digits[0] < 2 || *it < 5))
    {
        
        digits[1] = *it;
        digits[2] = min;
        digits[3] = min;
        
        return format(digits);
    }

    for(auto i = 0 ; i < 4 ; ++i)
    {
        digits[i] = min;
    }

    return format(digits);
}
};
