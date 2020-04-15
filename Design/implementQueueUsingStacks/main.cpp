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

class MyQueue {
    private:
        stack<int> s;
    public:
        MyQueue() {}

        void push(int i) {
            stack<int> tmp;
            while(!s.empty()) {
                tmp.push(s.top());
                s.pop();
            }
            s.push(i);
            while(!tmp.empty()) {
                s.push(tmp.top());
                tmp.pop();
            }
        }

        int pop() {
            auto res = s.top();
            s.pop();
            return res;
        }

        int peek() const {
            return s.top();
        }

        bool empty() const {
           return s.empty();
        }

};

class MyQueueTwoStacks {
    private:
        stack<int> s1, s2;
        int front;
    public:
        MyQueueTwoStacks() {}

        void push(int i) {
            if (s1.empty()) {
                front = i;
            }
            s1.push(i);
        }

        int pop() {
            if (s2.empty()) {
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            auto res = s2.top();
            s2.pop();
            return res;
        }

        int peek() const {
            if(!s2.empty()) {
                return s2.top();
            }
            return front;
        }

        bool empty() const {
            return s1.empty() && s2.empty();
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

        MyQueueTwoStacks queue;

        for(int i = 0 ; i < n ; ++i) {
            char buffer[50];
            memset(buffer, '\0', sizeof buffer);
            fastscan_char_w((char (&)[])buffer, 50);
            if (!strcmp(buffer,"push")) {
                int num = 0;
                fastscan(num);
                queue.push(num);
            } else if (!strcmp(buffer,"peek")) {
                printf("%d\n", queue.peek());
            } else if (!strcmp(buffer,"pop")) {
                printf("%d\n", queue.pop());
            } else if (!strcmp(buffer,"empty")) {
                printf("%s\n", queue.empty() ? "true" : "false");
            }
        }
    }

    return 0;
}
