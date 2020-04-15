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

#define wl(n) while(n--)
#define min(a,b) a < b ? a : b
#define max(a,b) a < b ? b : a
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

class Solution {
private:
public:
    int minDistance_2d(string word1, string word2) {
        int edit_dist[word1.length() + 1];

        for(int i = 0 ; i <= word1.length() ; ++i)
        {
            edit_dist[i] = i;
        }

        for(int i = 0; i < word2.length(); ++i)
        {
            auto diag = edit_dist[0];
            edit_dist[0] = i + 1;
            for (int j = 0 ; j < word1.length() ; ++j)
            {
                auto tmp = edit_dist[j+1];
                if(word1[j] == word2[i])
                {
                    edit_dist[j+1] = diag;
                }
                else {
                    edit_dist[j+1] = min(
                                     min(
                                         edit_dist[j] + 1,
                                         edit_dist[j+1] + 1
                                         ),
                                     diag + 1
                                     );
                }
                diag = tmp;
            }
        }

        auto res = edit_dist[word1.length()];

        return res;
    }

    int minDistance_rec(string word1, string word2) {
        if(word1.length() == 0 || word2.length() == 0)
        {
            return max(word1.length(), word2.length());
        }

        if (word1[0] == word2[0]) {
            return minDistance_rec(word1.substr(1), word2.substr(1));
        }
        else {
            auto replaced = word1;
            replaced[0] = word2[0];
            return min(
                       min(
                           minDistance_rec(word1.substr(1), word2) + 1, // Removed a letter
                           minDistance_rec(word1, word2.substr(1)) + 1  // Insert a letter
                           ),
                       minDistance_rec(replaced, word2) + 1// Replace letter
                       );
        }
    }
};

inline void fastscan(int& number)
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
             && c != '\0';
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
        string word1 = "";
        cin >> word1;
        string word2 = "";
        cin >> word2;

        auto res = Solution().minDistance_2d(word1, word2);
        printf("%d\n", res);
    }

    return 0;
}
