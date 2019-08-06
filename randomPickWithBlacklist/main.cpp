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

#define wl(n) while(n--)
#define min(a,b) a < b ? a : b
#define max(a,b) a < b ? b : a
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

class Solution {
private:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    int* map;
    int bound;
public:
    Solution(int N, vector<int>& blacklist): gen(mt19937(random_device()())), dis(uniform_int_distribution<int>(0,N - 1 - blacklist.size())), bound(N-blacklist.size()) {
        sort(blacklist.begin(), blacklist.end());
        map = new int[N];
        int k = 0;
        for(int i = 0, j = 0; i < N ; ++i, ++j) {
            while(k < blacklist.size() && blacklist[k] == j) {++j; ++k;}
            map[i] = j;
        }
        srand(time(NULL));
    }

    ~Solution() {
        delete[] map;
    }

    int pick() {
        int picked = bound;
        while (picked >= bound) {
            picked = rand() / ((RAND_MAX + 1u) / bound);
        }
        return map[picked];
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
        int nb_blacklist = 0;
        fastscan(nb_blacklist);
        auto blacklist = vector<int>(nb_blacklist, 0);

        int i;
        fl(i, 0, nb_blacklist){
            fastscan(blacklist[i]);
        }

        auto rand_gen = Solution(n, blacklist);

        int nb_pick = 0;
        fastscan(nb_pick);

        printf("N = %d, nb_blacklist: %d, nb_pick: %d\n", n, nb_blacklist, nb_pick);
        for(auto& b: blacklist) {
            printf("%d ", b);
        }
        printf("\n");
        wl(nb_pick) {
            auto res = rand_gen.pick();
            printf("%d ", res);
        }
        puts("");
    }

    return 0;
}
