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
        stack<pair<int, int>> s;
    public:
        /** initialize your data structure here. */
        MinStack(): s(stack<pair<int, int>>()) {
        }

        void push(int x) {
            int m = x;
            if(!s.empty()) {
                m = min(m, s.top().second);
            }
            s.emplace(make_pair(x, m));
        }

        void pop() {
            if(!s.empty()) {
                s.pop();
            }
        }

        int top() const {
            if(s.empty()) {
                exit(1);
            }
            return s.top().first;
        }

        int getMin() {
            if(s.empty()) {
                exit(1);
            }
            return s.top().second;
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
