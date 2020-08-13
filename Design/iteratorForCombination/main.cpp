#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "input.hpp"

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)

#define SIZE 1001

using namespace std;


static int fast_stream = []() {
                             ios::sync_with_stdio(false);
                             cin.tie(nullptr);
                             cout.tie(nullptr);
                             return 0;
                         }();

class CombinationIterator {
    private:
    stack<int> ptrs;
    string res, chs;
    int cn;
    bool hasN;
public:
    CombinationIterator(string characters, int combinationLength): chs(characters), cn(combinationLength), hasN(true) {
        for (int i = 0 ; i < cn ; ++i) {
            ptrs.push(i);
            res.push_back(chs[i]);
        }
    }

    string next() {
        int i = 0, t = -1;
        string ret = res;

        while(!ptrs.empty()) {
            t = ptrs.top(); ptrs.pop();
            res.pop_back();
            if(t+1 < (int)(chs.size()) - i) break;
            ++i;
        }

        if(ptrs.empty() && t == (int)(chs.size()) - cn) {
            hasN = false;
        }
        else {
            while(ptrs.size() < cn) {
                ptrs.push(++t);
                res.push_back(chs[t]);
            }
        }

        return ret;

    }

    bool hasNext() {
        return hasN;
    }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, k = 0;
        cin >> n >> k;
        string characters;
        characters.reserve(n);

        cin >> characters;

        CombinationIterator ci(characters, k);

        int m = 0;
        cin >> m;
        for(int i = 0 ; i < m ; ++i) {
            int cmd = -1;
            cin >> cmd;

            switch(cmd) {
                case 0: {
                    bool ret_hasNext = ci.hasNext();
                    printf("%s\n", ret_hasNext ? "True": "False");
                    break;
                }
                case 1: {
                    string ret_next = ci.next();
                    printf("%s\n", ret_next.c_str());
                    break;
                }
                default: {
                    printf("Unknown command\n");
                    break;
                }
            }
        }
    }

    return 0;
}
