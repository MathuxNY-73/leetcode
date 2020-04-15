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

TreeNode* createNode(int val) {
    TreeNode* n = malloc(sizeof(TreeNode));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void deleteTree(TreeNode* root) {
    if(root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

typedef struct Queue {
    TreeNode** queue;
    int size;
    int count;
    int front_idx;
    int back_idx;
} Queue;

Queue* createQueue(int size) {
    TreeNode** queue = malloc(sizeof(TreeNode*)*size);
    for(int i = 0 ; i < size ; ++i) {
        queue[i] = NULL;
    }
    Queue* q = malloc(sizeof(Queue));
    q->queue = queue;
    q->size = size;
    q->front_idx = 0;
    q->back_idx = -1;
    q->count = 0;
    return q;
}

void deleteQueue(Queue* q) {
    free(q->queue);
    free(q);
}

void pushQueue(Queue* q, TreeNode* el) {
    if(q->count < q->size) {
        q->queue[(++q->back_idx) % q->size] = el;
        ++q->count;
    }
}

void popQueue(Queue* q) {
    if(q->count > 0) {
        q->queue[((q->front_idx)++) % q->size] = 0;
        --q->count;
    }
}

int treeDFS(struct TreeNode* root, int sum) {

    if(root == NULL) {
        return 0;
    }

    sum = sum * 10 + root->val;

    if(root->left ==  NULL && root->right == NULL) {
        return sum;
    }
    else {
        int l = treeDFS(root->left, sum);
        int r = treeDFS(root->right, sum);

        return r+l;
    }
}

int sumNumbers(struct TreeNode* root){
    return treeDFS(root, 0);
}

int main()
{
    int t;
    fastscan(&t);

     wl(t)
    {
        int n=0;
        fastscan(&n);

        if(n == 0) {
            printf("0\n");
            continue;
        }

        char number[100];
        memset(number, '\0', sizeof(char)*100);
        fastscan_string_w(number, 100);

        if(!strncmp(number,"null", 4)) {
            exit(1);
        }
        int val = atoi(number);
        TreeNode* root = createNode(val);
        memset(number, '\0', sizeof(char)*100);

        Queue* q = createQueue(20);
        pushQueue(q, root);

        int i = 1;
        while(q->count && i < n) {
            TreeNode* cur = q->queue[q->front_idx];
            popQueue(q);

            fastscan_string_w(number, 100);
            printf("Left of %d is %s\n", cur->val, number);
            if(!strncmp(number,"null", 4)) {
                cur->left = NULL;
            }
            else {
                cur->left = createNode(atoi(number));
            }
            memset(number, '\0', sizeof(char)*100);
            pushQueue(q, cur->left);
            ++i;

            fastscan_string_w(number, 100);
            printf("Right of %d is %s\n", cur->val, number);
            if(!strncmp(number, "null", 4)) {
                cur->right = NULL;
            }
            else {
                cur->right = createNode(atoi(number));
            }
            memset(number, '\0', sizeof(char)*100);
            pushQueue(q, cur->right);
            ++i;
        }
        deleteQueue(q);

        int res = sumNumbers(root);
        printf("%d\n", res);
        deleteTree(root);
    }

    return 0;
}
