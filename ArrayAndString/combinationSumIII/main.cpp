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

class Solution {
    private:
        void helper(const vector<int>& candidates, int startIdx, int sum, int target, vector<int> cur, vector<vector<int>>& res) {
            if(sum > target) return;
            if(sum == target) {
                res.push_back(cur);
                return;
            }

            for(int i = startIdx + 1; i < candidates.size(); ++i) {
                if(i > startIdx + 1 && candidates[i - 1] == candidates[i]) continue;
                int new_sum = sum + candidates[i];
                if(new_sum > target) return;
                cur.push_back(candidates[i]);
                helper(candidates, i, new_sum, target, cur, res);
                cur.pop_back();
            }
        }

    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            int n = candidates.size();
            if(n == 0) return {};

            sort(candidates.begin(), candidates.end());

            vector<vector<int>> res;
            for(int i = 0 ; i < n && candidates[i] <= target ; ++i) {
                if(i > 0 && candidates[i - 1] == candidates[i]) continue;
                auto cur = vector<int>();
                cur.push_back(candidates[i]);
                helper(candidates, i, candidates[i], target, cur, res);
            }
            return res;
        }

};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, target = 0;
        cin >> n >> target;

        vector<int> candidates(n, 0);
        for(auto& el: candidates) {
            cin >> el;
        }
        vector<vector<int>> res = Solution().combinationSum2(candidates, target);

        for(auto& comb: res) {
            cout << "[";
            for(auto& el: comb) {
                cout << el << " ";
            }
            cout << "]\n";
        }
        cout << "\n";
    }

    return 0;
}
