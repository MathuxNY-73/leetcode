#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#include "input.h"

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)
#define min(a,b) a<=b?a:b

typedef struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
} TreeNode;

int p[1000];

int treeDFS(struct TreeNode* root, int depth) {

    if(root == NULL) {
        return 0;
    }

    p[depth++] = root->val;

    if(root->left ==  NULL && root->right == NULL) {
        int res = 0;
        for(int i=0 ; i < depth ; ++i) {
            res = res * 10 + p[i];
        }
        return res;
    }
    else {
        int l = treeDFS(root->left, depth);
        int r = treeDFS(root->right, depth);

        return r+l;
    }
}

int sumNumbers(struct TreeNode* root){
    memset(p, 0, sizeof(int) * 1000);
    return treeDFS(root, 0);
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n=0;
        fastscan(&n);
        int nb_blacklist = 0;
        fastscan(&nb_blacklist);
        int* blacklist = malloc(sizeof(int) * nb_blacklist);

        int i;
        fl(i, 0, nb_blacklist){
            fastscan(&blacklist[i]);
        }

        Solution* rand_gen = solutionCreate(n, blacklist, nb_blacklist);

        int nb_pick = 0;
        fastscan(&nb_pick);

        int test[7] = {3,2,6,5,9,1,4};
        heap_sort(&test, 7);
        for(int i = 0 ; i < 7 ; ++i) {
            printf("%d ", test[i]);
        }
        printf("\n");
        printf("2: %d\n", bin_search(2, blacklist, nb_blacklist));
        printf("1: %d\n", bin_search(1, blacklist, nb_blacklist));

        printf("N = %d, nb_blacklist: %d, nb_pick: %d\n", n, nb_blacklist, nb_pick);
        wl(nb_pick) {
            int res = solutionPick(rand_gen);
            printf("%d ", res);
        }

        solutionFree(rand_gen);
        free(blacklist);
        puts("");
    }
    return 0;
}
