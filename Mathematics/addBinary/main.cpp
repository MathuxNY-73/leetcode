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
    template<class T>
    void print(const vector<T>& a) const {
        for(auto x: a)
        {
            cout << x;
        }
        cout << endl;
    }
    
public:
    string addBinary(string a, string b) {
        auto res = vector<char>(max(a.size(),b.size()));
        auto a_v = vector<int>(a.size());
        auto b_v = vector<int>(b.size());
        auto ret = 0;
        auto i = 0;
        
        auto k = 0;
        for(auto it = a.crbegin() ; it != a.crend() ; ++it, ++k)
        {
            a_v[k] = *it - '0';
        }
        
        k = 0;
        for(auto it = b.crbegin() ; it != b.crend() ; ++it, ++k)
        {
            b_v[k] = *it - '0';
        }
        
        //print(a_v);
        //print(b_v);
        
        for(; i < a_v.size() && i < b_v.size() ; ++i)
        {
            auto cur_a = a_v[i];
            auto cur_b = b_v[i];
            
            auto add = cur_a + cur_b + ret;
             
            //cout << "cur_a:" << cur_a << " cur_b:" << cur_b << endl;
            if(add == 2)
            {
                //cout << "Hello 1" << endl;
                ret = 1;
                res[i] = '0';
            }
            else if(add == 3)
            {
                //cout << "Hello 2" << endl;
                ret = 1;
                res[i] = '1';
            }
            else
            {
                //cout << "Hello 3" << endl;
                ret = 0;
                res[i] = add + '0';
            }
            //print(res);
        }
        
        if(a_v.size() < b_v.size())
        {
            for(; i < b_v.size() ; ++i)
            {
                auto cur_b = b_v[i];
            
                auto add = cur_b + ret;
            
                if(add == 2)
                {
                    ret = 1;
                    res[i] = '0';
                }
                else
                {
                    ret = 0;
                    res[i] = add + '0';
                }
            }
            print(res);
        }
        else if(a_v.size() > b_v.size())
        {
            for(; i < a_v.size() ; ++i)
            {
                auto cur_a = a_v[i];
                
                //cout << "cur_a:" << cur_a << endl;
                auto add = cur_a + ret;
            
                if(add == 2)
                {
                    ret = 1;
                    res[i] = '0';
                }
                else
                {
                    ret = 0;
                    res[i] = add + '0';
                }
            
            }
            print(res);
        }
        if(ret == 1)
        {
            res.push_back('1');
        }
        
        //print(res);
        //cout << res.size() << endl;
        
        //string res_str;
        
        auto res_str = "" + string(res.crbegin(), res.crend());
        /*if(res.size() == 1)
        {
            res_str = string(1, res[0]);
        }
        else
        {
            res_str = string(res.crbegin(), res.crend());
        }*/
        
        return res_str;
    }
};

int main()
{
        string a, b;
        scanf("%s" ,&a);
        scanf("%s", &b);

        Solution solution;
        auto result = solution.addBinary(a, b);

        printf("%s", result);

        printf("\n");

    return 0;
}