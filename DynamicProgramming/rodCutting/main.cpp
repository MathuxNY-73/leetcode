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
    public:

        pair<long long, vector<int>> helper(int start, int end, int l, int r, vector<int>& weak_points, unordered_map<int, unordered_map<int, pair<long long, vector<int>>>>& dp) {

            if(l == r) return make_pair(0LL, vector<int>());
            if(dp.find(start) != dp.cend()) {
                if(dp[start].find(end) != dp[start].cend()) return dp[start][end];
            }
            else {
                dp[start] = unordered_map<int, pair<long long, vector<int>>>();
            }


            long long min_cut = numeric_limits<long long>::max();
            vector<int> best_sequence;
            for(int i = l; i < r ; ++i) {
                long long cost_of_cut_left = 0LL;
                vector<int> sequence_of_cuts_left;
                tie(cost_of_cut_left, sequence_of_cuts_left) =
                    helper(start, weak_points[i], l, i, weak_points, dp);

                long long cost_of_cut_right = 0LL;
                vector<int> sequence_of_cuts_right;
                tie(cost_of_cut_right, sequence_of_cuts_right) =
                    helper(weak_points[i], end, i + 1, r, weak_points, dp);

                if(min_cut >= cost_of_cut_left + cost_of_cut_right) {
                    sequence_of_cuts_left.insert(sequence_of_cuts_left.end(),
                        sequence_of_cuts_right.begin(),
                        sequence_of_cuts_right.end());
                    sequence_of_cuts_left.insert(sequence_of_cuts_left.begin(), weak_points[i]);
                    if(best_sequence.size() == 0 || (min_cut > cost_of_cut_left + cost_of_cut_right ||
                        sequence_of_cuts_left < best_sequence)) {
                            best_sequence = sequence_of_cuts_left;
                    }
                    min_cut = cost_of_cut_left +cost_of_cut_right;
                }

            }
            dp[start][end] = make_pair(min_cut + (long)end - (long)start, best_sequence);
            return dp[start][end];
        }


        vector<int> rodCut(int A, vector<int> &B) {

            unordered_map<int, unordered_map<int, pair<long long, vector<int>>>> dp;
            pair<long long, vector<int>> result = helper(0, A, 0, B.size(), B, dp);
            return result.second;
        }

        vector<int> extractCutSequence(const vector<vector<long long>>& costs, const vector<int> cuts, int start, int end) {
            if(end - start > 1) {
                for(int cut = start + 1; cut < end; ++cut) {
                    long long cost = costs[start][cut] + costs[cut][end] + (long long)cuts[end] - (long long)cuts[start];
                    if(costs[start][end] == cost) {
                        vector<int> leftCutSequence = extractCutSequence(costs, cuts, start, cut);
                        vector<int> rightCutSequence = extractCutSequence(costs, cuts, cut, end);

                        if(leftCutSequence > rightCutSequence) swap(leftCutSequence, rightCutSequence);

                        vector<int> cutSequence(leftCutSequence.size() + rightCutSequence.size() + 1, 0);
                        int i = 0;
                        cutSequence[i++] = cuts[cut];
                        for(auto& c: leftCutSequence) cutSequence[i++] = c;
                        for(auto& c: rightCutSequence) cutSequence[i++] = c;
                        return cutSequence;
                    }
                }
            }
            return {};
        }

        vector<int> rodCutDp(int n, vector<int>& cuts) {
            cuts.insert(cuts.begin(), 0);
            cuts.push_back(n);

            int cuts_size = cuts.size();
            if(cuts_size < 3) return {};

            sort(cuts.begin(), cuts.end());

            vector<vector<long long>> minCosts(cuts_size, vector<long long>(cuts_size, numeric_limits<long long>::max()));

            for(int i = 0 ; i < cuts_size ; ++i) {
                minCosts[i][i] = 0;
                if(i < cuts_size - 1) minCosts[i][i + 1] = minCosts[i + 1][i] = 0;
            }

            for(int l = 3 ; l <= cuts_size ; ++l) {
                for(int start = 0, end = l - 1; end < cuts_size ; ++start, ++end) {
                    for(int cut = start + 1; cut < end ; ++cut) {
                        minCosts[start][end] = min(minCosts[start][end], minCosts[start][cut] + minCosts[cut][end] + (long long)(cuts[end] - cuts[start]));
                    }
                }
            }
            //cout << " Min cost=" << minCosts[0][cuts_size - 1] << "\n";
            return extractCutSequence(minCosts, cuts, 0, cuts_size - 1);
        }
};

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, w = 0;
        cin >> n >> w;

        vector<int> array(w, 0);
        for(auto& e: array) {
            cin >> e;
        }

        auto res = Solution().rodCutDp(n, array);

        for(auto& x: res) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
