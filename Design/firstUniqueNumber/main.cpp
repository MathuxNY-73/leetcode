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

class FirstUnique {
    private:
        unordered_map<int, pair<bool, list<int>::iterator>> m;
        list<int> q;

    public:
        FirstUnique(const vector<int>& nums) {
            for(auto& x: nums) {
                add(x);
            }
        }

        int showFirstUnique() {
            if (q.empty())
                return -1;
            return q.front();
        }
    
        void add(int value) {
            auto it = m.find(value);
            if(it == m.cend()) {
                q.emplace_back(value);
                m.emplace(value, make_pair(true, prev(q.end())));
            }
            else {
                if (it->second.first) {
                    q.erase(it->second.second);
                    it->second.first = false;
                }
            }
        }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, m = 0;
        cin >> n >> m;
        vector<int> nums(m, 0);

        for(auto& x: nums) {
            cin >> x;
        }

        FirstUnique fu(nums);

        for(int i = 0 ; i < n ; ++i) {
            string cmd;

            cin >> cmd;
            //cout << "test " << cmd << "\n";
            if (cmd == "add") {
                int k = 0;
                cin >> k;

                fu.add(k);
            }
            else if(cmd == "showFirstUnique") {
                cout << fu.showFirstUnique() << "\n";
            }
        }
    }

    return 0;
}
