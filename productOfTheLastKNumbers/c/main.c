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
#define min(a,b) (a<=b?a:b)
#define max(a,b) (a>=b?a:b)

#define SIZE 160000

int tree[SIZE];
typedef struct {
    int* t;
    int cnt;
} ProductOfNumbers;

void add_to_tree(ProductOfNumbers*, int, int, int, int, int);
int get_product(ProductOfNumbers*, int, int, int, int, int);

ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* pon = malloc(sizeof(ProductOfNumbers));
    memset(tree, 1, sizeof(tree));
    pon->t = tree;
    pon->cnt = 0;
    return pon;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    add_to_tree(obj, 1, 0, 0, obj->cnt, num);
    obj->cnt++;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    return get_product(obj, 1, 0, obj->cnt, obj->cnt - k , obj->cnt);
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj);
}

void add_to_tree(ProductOfNumbers* obj, int v, int pos, int l, int r, int num) {
    if (l == r) {
        obj->t[l] = num;
    }
    else {
        int m = (l + r) / 2;
        if (pos <= m) {
            add_to_tree(obj, v*2, pos, l, m, num);
        }
        else {
            add_to_tree(obj, v*2 + 1, pos, m + 1, r, num);
        }
        obj->t[v] = obj->t[v*2] * obj->t[v*2 + 1];

    }
}

int get_product(ProductOfNumbers* obj, int v, int l, int r, int l_s, int r_s) {
    if (r < l) {
        return 1;
    }
    else if (l == l_s && r == r_s){
        return obj->t[v];
    }
    else {
        int m = (l + r) / 2;
        return get_product(obj, v*2, l, m, l_s, min(m, r_s)) *
            get_product(obj, v*2 + 1, m+1, r, max(m+1, l_s), r_s);
    }

}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n=0;
        fastscan(&n);
        ProductOfNumbers* pon = productOfNumbersCreate();
        const char f[] = {'f'};

        int i;
        fl(i, 0, n){
            char str_buf[7];
            memset(str_buf,'\0',sizeof(str_buf));

            fastscan_string_w(str_buf, 7);
            if (!strcmp(str_buf,f)) {
                memset(str_buf,'\0',sizeof(str_buf));
                fastscan_string_w(str_buf, 7);
                printf("%d\n", productOfNumbersGetProduct(pon, atoi(str_buf)));
            }
            else {
                productOfNumbersAdd(pon, atoi(str_buf));
            }
        }

        productOfNumbersFree(pon);
    }
    return 0;
}
