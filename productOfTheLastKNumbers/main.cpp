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

class ProductOfNumbers {
private:
    vector<int> prefix_prod;
    bool zero;
public:
    ProductOfNumbers(): zero(false) {
    }

    void add(int num) {
        if (!num) {
            zero = true;
            prefix_prod.clear();
        } else {
            auto pred = 1;
            if (!prefix_prod.empty()) {
                pred = prefix_prod.back();
            }
            prefix_prod.emplace_back(pred * num);
        }
        print();
    }

    void print() {
        for(auto el: prefix_prod) {
            fprintf(stderr, "%d ", el);
        }
        fprintf(stderr, "\n");
    }

    int getProduct(int k) {
        // assuming that there is always at leas k element in the list
        int s = prefix_prod.size();
        fprintf(stderr, "prefix_prod size = %d and k = %d\n", s, k);
        if (s <= k) {
            if (s < k && zero) {
                return 0;
            }
            else {
                return prefix_prod.back();
            }
        }
        return (int)(prefix_prod.back() / prefix_prod[prefix_prod.size() - k - 1]);
    }
};

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        ProductOfNumbers pon;
        int n=0;
        fastscan(n);

        for(int i = 0 ; i < n ; ++i) {
            char buffer[50];
            memset(buffer, '\0', sizeof buffer);
            fastscan_char_w((char (&)[])buffer, 50);
            if (buffer[0] == 'f') {
                memset(buffer, '\0', sizeof buffer);
                fastscan_char_w((char (&)[])buffer, 50);
                auto med = pon.getProduct(stoi(buffer));
                printf("%d\n", med);
            }
            else {
                int num = stoi(buffer);
                pon.add(num);
            }
        }
    }

    return 0;
}
