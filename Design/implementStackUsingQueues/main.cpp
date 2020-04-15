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

using namespace std;

static int fast_stream = []() {
                             ios::sync_with_stdio(false);
                             cin.tie(nullptr);
                             cout.tie(nullptr);
                             return 0;
                         }();

class MyStack {
    private:
        queue<int> q1, q2;
        queue<int>& active;
        int t;
    public:
        MyStack(): active(q1) {}

        void push(int i) {
            active.push(i);
            t = i;
        }

        int pop() {
            auto prev = active;
            active = q1.empty() ? q1 : q2;
            while (prev.size() > 1) {
                t = prev.front();
                active.push(t);
                prev.pop();
            }
            auto res = prev.front();
            prev.pop();
            return res;
        }

        int top() const {
            return t;
        }

        bool empty() const {
           return active.empty();
        }

};

class MyStackOneQueue {
    private:
        queue<int> q;
    public:
        MyStackOneQueue() {}

        void push(int i) {
            q.push(i);
            int k = 0;
            while(k < q.size() - 1) {
                q.push(q.front());
                q.pop();
                ++k;
            }
        }

        int pop() {
            auto res = q.front();
            q.pop();
            return res;
        }

        int top() const {
            return q.front();
        }

        bool empty() const {
            return q.empty();
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

        MyStackOneQueue stack;

        for(int i = 0 ; i < n ; ++i) {
            char buffer[50];
            memset(buffer, '\0', sizeof buffer);
            fastscan_char_w((char (&)[])buffer, 50);
            if (!strcmp(buffer,"push")) {
                int num = 0;
                fastscan(num);
                stack.push(num);
            } else if (!strcmp(buffer,"top")) {
                printf("%d\n", stack.top());
            } else if (!strcmp(buffer,"pop")) {
                printf("%d\n", stack.pop());
            } else if (!strcmp(buffer,"empty")) {
                printf("%s\n", stack.empty() ? "true" : "false");
            }
        }
    }

    return 0;
}
