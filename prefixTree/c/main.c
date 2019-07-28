#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)
#define min(a,b) a<=b?a:b

typedef struct Node {
    char value;
    bool isEnd;

    struct Node* right;
    struct Node* center;
    struct Node* left;
} Node;

typedef struct {

    Node* root;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie* trie = malloc(sizeof(Trie));
    trie->root = NULL;
    return trie;
}

Node* newNode(char value) {

    Node* nNode = malloc(sizeof(Node));
    nNode->isEnd = false;
    nNode->value = value;
    return nNode;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Node** curNode = &(obj->root);
    char* curWord = word;

    while(*(curWord) != '\0') {
        if(!(*curNode)) {
            *(curNode) = newNode(*(curWord));
        }

        if((*curNode)->value < *(curWord)) {
            curNode = &(*curNode)->right;
        }
        else if ((*curNode)->value > *(curWord)) {
            curNode = &(*curNode)->left;
        }
        else {
            if(*(++curWord)) {
                curNode = &(*curNode)->center;
            }
            else {
                (*curNode)->isEnd = true;
            }
        }
    }
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    Node** curNode = &obj->root;
    char* curWord = word;

    while(*(curWord) != '\0') {
        if (!(*curNode)) {
            return false;
        }

        if((*curNode)->value < *(curWord)) {
            curNode = &(*curNode)->right;
        }
        else if ((*curNode)->value > *(curWord)) {
            curNode = &(*curNode)->left;
        }
        else {
            if(*(++curWord)) {
                curNode = &(*curNode)->center;
            }
        }
    }

    return (*curNode)->isEnd;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    Node** curNode = &obj->root;
    char* curWord = prefix;

    while(*(curWord) != '\0') {
        if (!(*curNode)) {
            return false;
        }

        if((*curNode)->value < *(curWord)) {
            curNode = &(*curNode)->right;
        }
        else if ((*curNode)->value > *(curWord)) {
            curNode = &(*curNode)->left;
        }
        else {
            if(*(++curWord)) {
                curNode = &(*curNode)->center;
            }
        }
    }

    return true;
}

void freeDF(Node* root) {
    if(!(root->left)) {
        freeDF(root->left);
    }
    if(!root->center) {
        freeDF(root->center);
    }
    if(!root->right) {
        freeDF(root->right);
    }
    free(root);
}

void trieFree(Trie* obj) {
    freeDF(obj->root);
    free(obj);
}

void fastscan(int* number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    *number = 0;
 
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
        *number = *number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        *number *= -1;
}

int fastscan_string_w(char *str, int buffer_size)
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
    int t = 0;
    fastscan(&t);

    wl(t) {
        int n=0;
        fastscan(&n);
        Trie* trie = trieCreate();
        wl(n) {
            int k = 0;
            fastscan(&k);
            //printf("%d\n", k);
            char s[100];
            memset(s, '\0', sizeof(char) * 100);
            fastscan_string_w(s, 100);
            //printf("%s\n", s);
            switch(k) {
            case 1: {
                trieInsert(trie, s);
                break;
            }
            case 2: {
                //printf("%s\n", s);
                bool res_search= trieSearch(trie, s);
                printf(res_search ? "True" : "False");
                printf("\n");
                break;
            }
            case 3: {
                bool res_start = trieStartsWith(trie, s);
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
