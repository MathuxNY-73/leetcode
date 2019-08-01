#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <stack>
#include <array>
#include <stdexcept>

#define wl(n) while(n--)
#define min(a,b) a < b ? a : b
#define max(a,b) a < b ? b : a
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

void print_vector(const vector<int>& v) {
    printf("[%d, %d]\n", v[0], v[1]);
}

class Solution {
public:

    static vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        auto r_nodes = unordered_map<int, unordered_set<int>>();
        auto p_nodes = unordered_map<int, unordered_set<int>>();

        for(auto& edge: edges) {
            auto it_p = p_nodes.find(edge[1]);
            auto it = r_nodes.find(edge[0]);
            if(it == r_nodes.cend()) {
                r_nodes[edge[0]] = unordered_set<int>();
                r_nodes[edge[0]].emplace(edge[1]);
            }
            else {
                printf("%d: ", it->first);
                for(auto& r: it->second) {
                    printf("%d, ", r);
                }
                printf("\n");
                if(it->second.find(edge[1]) != it->second.cend()) {
                    return edge;
                }
                else {
                    it->second.emplace(edge[1]);
                }
            }
        }
        return vector<int>(2, -1);
    }

};

static inline void fastscan(int& number)
{
    //variable to indicate sign of input number
    bool negative = false;
    int c;

    number = 0;

    // extract current character from buffer
    c = getchar_unlocked();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar_unlocked();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

static inline int fastscan_string_w(char (&str)[], int buffer_size)
{
    char c;
    int size_of_str = 0;

    // extract current character from buffer
    c = getchar_unlocked();

    // Keep on extracting characters if they are not
    // space, carriage return or end of string
    for (; c != ' '
             && c != '\n'
             && c != '\0'
             && c != EOF;
         c=getchar_unlocked(),++size_of_str)
        {
            if(size_of_str > buffer_size)
                exit(-1);
            str[size_of_str] = c;
        }
    return  size_of_str;
}

int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        int n=0;
        fastscan(n);
        auto edges = vector<vector<int>>(n, vector<int>(2, 0));

        int i;
        fl(i, 0, n){
            fastscan(edges[i][0]);
            fastscan(edges[i][1]);
        }
        auto res = Solution::findRedundantDirectedConnection(edges);
        print_vector(res);

    }

    return 0;
}
