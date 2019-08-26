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

typedef struct {
    // User defined data may be declared here.
    volatile int* first;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    // Initialize user defined data here.
    obj->first = malloc(sizeof(int));
    *(obj->first) = 0;
    return obj;
}

void first(Foo* obj) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    *(obj->first) = 1;
}

void second(Foo* obj) {
    // printSecond() outputs "second". Do not change or remove this line.
    while(1) {
        if(*(obj->first)==1) {
            break;
        }
        usleep(5);
    }
    printSecond();
    *(obj->first) = 2;
}

void third(Foo* obj) {
    // printThird() outputs "third". Do not change or remove this line.
    while(1) {
        if(*(obj->first)==2) {
            break;
        }
        usleep(5);
    }
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    free(obj->first);
    free(obj);
}

int main()
{
    return 0;
}
