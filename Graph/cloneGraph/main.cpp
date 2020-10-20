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

class Node {
    public:
        int val;
        vector<Node*> neighbors;

        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }

        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }

        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
};

class Solution {
    public:
        Node* cloneGraph(Node* node) {
            if(node == nullptr) return nullptr;

            queue<Node*> q;
            unordered_map<int, Node*> new_nodes;

            auto new_node = new Node(node->val);
            new_nodes[new_node->val] = new_node;

            q.push(node);
            while(!q.empty()) {
                auto cur = q.front(); q.pop();

                for(auto& nei: cur->neighbors) {
                    if(nei != nullptr) {
                        if(new_nodes.find(nei->val) == new_nodes.cend()) {
                            new_nodes[nei->val] = new Node(nei->val);
                            q.push(nei);
                        }
                        new_nodes[cur->val]->neighbors.push_back(new_nodes[nei->val]);
                    }
                }

            }
            return new_node;
        }
};

bool compare(Node* a, Node* b, unordered_set<int>&& visited) {
    if(a != nullptr && b != nullptr) {
        //cout << "Comparing a=" << a->val << " (neighbors="<< a->neighbors.size() << ") and b=" << b->val << "(neighbors="<< b->neighbors.size() << ")\n";
        if(visited.find(a->val) == visited.cend() && visited.find(b->val) == visited.cend()) {
            //cout << "Not Visited\n";
            if(a->val != b->val) return false;

            int n = a->neighbors.size();
            if(b->neighbors.size() != n) return false;

            visited.insert(a->val);
            bool check = true;
            for(int i = 0 ; i < n ; ++i) {
                check &= compare(a->neighbors[i], b->neighbors[i], move(visited));
            }

            return check;
        }
        else if(visited.find(a->val) != visited.cend() && visited.find(b->val) != visited.cend()) {
            //cout << "Visited\n";
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;

    wl(t)
    {
        int n=0, m=0, s=0;
        cin >> n >> m >> s;

        vector<Node> nodes(n, Node());
        for(int i = 1 ; i <= n ; ++i)
            nodes[i - 1].val = i;

        cin.ignore();
        for(int i = 0 ; i < m ; ++i) {
            string adj;
            getline(cin, adj);
            //cout << "For node=" << i +1 << " " << adj << "\n";
            string token;
            istringstream iss(adj);
            while (getline(iss, token, ' ')) {
                int node = stoi(token);
                cout << "Node=" << node << " is adjacent to " << i + 1 << "\n";
                nodes[i].neighbors.push_back(&nodes[node-1]);
            }
        }

        auto res = Solution().cloneGraph(&nodes[s - 1]);

        //cout << res << "\n";
        bool cmp = compare(&nodes[s-1], res, unordered_set<int>());

        cout << (cmp ? "True" : "False") << "\n";

        unordered_set<int> visited;
        stack<Node*> st;
        st.push(res);
        while(!st.empty()) {
            auto cur = st.top();

            if(cur == nullptr) continue;

            visited.insert(cur->val);

            while(!cur->neighbors.empty() &&(cur->neighbors.back() == nullptr || visited.find(cur->neighbors.back()->val) != visited.cend())) cur->neighbors.pop_back();

            if(cur->neighbors.empty()) {
                st.pop();
                delete cur;
            }
            else {
                st.push(cur->neighbors.back());
                cur->neighbors.pop_back();
            }
        }
    }

    return 0;
}
