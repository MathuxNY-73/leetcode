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

typedef struct Node {
    char value;
    bool isLeaf;
    Node* children[26];

    Node(): value('\0'), isLeaf(true) {
        memset(children, 0, sizeof(Node*) * 26);
    }
    Node(char v, bool isLeaf): value(v), isLeaf(isLeaf) {
        memset(children, 0, sizeof(Node*) * 26);
    }
    ~Node() {
        for(auto& n: children) {
            delete n;
        }
    }

} Node;

class Trie {
    Node root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = Node('\0', false);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto cur = &root;
        for(const auto& c: word) {
            //printf("%p\n", cur);
            //printf("%c: %d\n", c, c-'a');
            //printf(!cur->children[c - 'a'] ? "True": "False");
            //printf("\n");
            //printf("1: %p\n",cur->children[c - 'a']);
            if(!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new Node(c, false);
            }
            //printf("2: %p\n",cur->children[c - 'a']);
            cur = cur->children[c-'a'];
            //printf("%p\n", cur);
        }
        cur->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto cur = &root;
        for(const auto& c: word) {
            //printf("%c: %d\n", c, c-'a');
            //printf("1: %p\n",cur->children[c - 'a']);
            if(!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return cur->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto cur = &root;
        for(const auto& c: prefix) {
            if(!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return true;
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
        auto trie = new Trie();
        wl(n) {
            int k = 0;
            fastscan(k);
            //printf("%d\n", k);
            char s[100];
            memset(s, '\0', sizeof(char) * 100);
            fastscan_string_w((char (&)[])s, 100);
            //printf("%s\n", s);
            switch(k) {
            case 1: {
                trie->insert(s);
                break;
            }
            case 2: {
                //printf("%s\n", s);
                auto res_search= trie->search(s);
                printf(res_search ? "True" : "False");
                printf("\n");
                break;
            }
            case 3: {
                auto res_start = trie->startsWith(s);
                printf(res_start ? "True" : "False");
                printf("\n");
                break;
            }
            }
        }
        printf("\n");
    }

    return 0;
}
