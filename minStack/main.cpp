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

class MinStack {
    private:
        vector<int> s;
        int m;
    public:
        /** initialize your data structure here. */
        MinStack(): s(vector<int>()), m(numeric_limits<int>::max()) {
        }

        void push(int x) {
            s.push_back(x);
            m = min(x, m);
        }

        void pop() {
            if(s.size() == 0) {
                return;
            }

            int rem = s.back();
            s.pop_back();

            if(rem == m) {
                m = numeric_limits<int>::max();
                for(auto& x: s) {
                    m = min(m, x);
                }
            }
        }

        int top() const {
            if(s.size() == 0) {
                exit(1);
            }

            return s.back();
        }

        int getMin() {
            return m;
        }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0;
        fastscan(n);
        MinStack ms;

        for(int i = 0 ; i < n ; ++i) {
            string cmd;

            cin >> cmd;
            if (cmd == "top") {
                cout << ms.top() << "\n";
            }
            else if(cmd == "pop") {
                ms.pop();
            }
            else if(cmd == "min") {
                cout << ms.getMin() << "\n";
            }
            else if(cmd == "push") {
                int v = 0;
                cin >> v;
                ms.push(v);
            }
        }
    }

    return 0;
}
