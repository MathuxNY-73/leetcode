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

class MedianFinder {
    private:
        priority_queue<int> lo;
        priority_queue<int, vector<int>, greater<int>> hi;

        template<class T, class U>
        void print_queue(priority_queue<int, T, U> q) const {
            while(!q.empty()) {
                fprintf(stderr, "%d ", q.top());
                q.pop();
            }
            fprintf(stderr, "\n");
        }

        void rebalance_queues() {
            while(hi.size() > lo.size()) {
                lo.push(hi.top());
                hi.pop();
            }

            while(lo.size() > hi.size() + 1) {
                hi.push(lo.top());
                lo.pop();
            }
        }
    public:
        MedianFinder() {}

        void addNum(int num) {
            if(!lo.empty() && num > lo.top()) {
                hi.push(num);
            }
            else {
                lo.push(num);
            }

            fprintf(stderr, "Before rebalancing queues:\nlo: ");
            print_queue(lo);
            fprintf(stderr, "hi: ");
            print_queue(hi);

            rebalance_queues();

            fprintf(stderr, "After rebalancing queues:\nlo: ");
            print_queue(lo);
            fprintf(stderr, "hi: ");
            print_queue(hi);
        }

        double findMedian() const {
            int tot = hi.size() + lo.size();

            if (!tot) {
                return 0;
            }

            if(tot & 1) {
                return (double)lo.top();
            }
            else {
                return ((double)lo.top() + hi.top()) / 2.0;
            }
        }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        MedianFinder mf;
        int n=0;
        fastscan(n);

        for(int i = 0 ; i < n ; ++i) {
            char buffer[50];
            memset(buffer, '\0', sizeof buffer);
            fastscan_char_w((char (&)[])buffer, 50);
            if (buffer[0] == 'f') {
                auto med = mf.findMedian();
                printf("%f\n", med);
            }
            else {
                int num = stoi(buffer);
                mf.addNum(num);
            }
        }
    }

    return 0;
}
