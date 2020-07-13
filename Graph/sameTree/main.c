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

#define QUEUE_SIZE 2048
#define BUFFER_SIZE 1024

static const char null_node[] = "N";

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createTreeNode() {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* readBinaryTree(int n) {
    struct TreeNode* root = NULL;

    char* buf[BUFFER_SIZE];
    memset(buf, '\0', sizeof(char) * BUFFER_SIZE);

    struct TreeNode* queue[QUEUE_SIZE];
    memset(queue, 0, sizeof(struct TreeNode*) * QUEUE_SIZE);

    fastscan_string_w((char*)buf, BUFFER_SIZE);
    --n;

    int front = 0, tail = 0;

    if(strcmp((char*)buf, null_node) != 0) {
        root = createTreeNode();
        int val = (int)strtol((char*)buf,(char**)NULL,10);
        root->val = val;
        queue[tail++] = root;
    }

    while(n > 0 && front != tail) {
        struct TreeNode* cur = queue[front++ % QUEUE_SIZE];

        memset(buf, '\0', sizeof(char) * BUFFER_SIZE);
        fastscan_string_w((char*)buf, BUFFER_SIZE);
        if(strcmp((char*)buf, null_node) != 0) {
            struct TreeNode* left = createTreeNode();
            int val = (int)strtol((char*)buf,(char**)NULL,10);
            left->val = val;
            queue[tail++ % QUEUE_SIZE] = left;
            cur->left = left;
        }
        --n;

        memset(buf, '\0', sizeof(char) * BUFFER_SIZE);
        fastscan_string_w((char*)buf, BUFFER_SIZE);
        if(strcmp((char*)buf, null_node) != 0) {
            struct TreeNode* right = createTreeNode();
            int val = (int)strtol((char*)buf,(char**)NULL,10);
            right->val = val;
            queue[tail++ % QUEUE_SIZE] = right;
            cur->right = right;
        }
        --n;
    }
    return root;
}

void deleteBinaryTree(struct TreeNode* root) {

    struct TreeNode* queue[QUEUE_SIZE];
    memset(queue, 0, sizeof(struct TreeNode*) * QUEUE_SIZE);

    int front = 0, tail = 0;

    if(root == NULL) {
        return;
    }
    queue[tail++] = root;

    while(front != tail) {
        struct TreeNode* cur = queue[front++ % QUEUE_SIZE];

        if(cur->left != NULL) {
            queue[tail++ % QUEUE_SIZE] = cur->left;
        }
        if(cur->right != NULL) {
            queue[tail++ % QUEUE_SIZE] = cur->right;
        }
        cur->left = cur->right = NULL;
        free(cur);
    }
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    else if (p != NULL && q != NULL) {
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right);
        }
    }
    return false;
}

int main()
{
    int t;
    fastscan(&t);

     wl(t)
    {
        int n=0, m=0;
        fastscan(&n);
        fastscan(&m);

        struct TreeNode* p = readBinaryTree(n);
        struct TreeNode* q = readBinaryTree(m);

        bool res = isSameTree(p, q);
       
        printf("%s\n", res ? "TRUE": "FALSE");

        deleteBinaryTree(p);
        deleteBinaryTree(q);
    }

    return 0;
}
