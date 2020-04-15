#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

#include "input.h"

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)
#define min(a,b) a<=b?a:b

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    free(obj->first);
    free(obj);
}

typedef struct {
    // User defined data may be declared here.
    int cnt;
    pthread_mutex_t lock;
    pthread_cond_t first_print;
    pthread_cond_t second_print;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));

    // Initialize user defined data here.
    obj->cnt = 0;
    pthread_mutex_init(&obj->lock, NULL);
    pthread_cond_init(&obj->first_print, NULL);
    pthread_cond_init(&obj->second_print, NULL);
    return obj;
}

void first(Foo* obj) {

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    pthread_mutex_lock(&obj->lock);
    obj->cnt = 1;
    pthread_mutex_unlock(&obj->lock);
    pthread_cond_signal(&obj->first_print);
}

void second(Foo* obj) {

    // printSecond() outputs "second". Do not change or remove this line.
    pthread_mutex_lock(&obj->lock);
    while(obj->cnt < 1) {
        pthread_cond_wait(&obj->first_print, &obj->lock);
    }
    printSecond();
    obj->cnt = 2;
    pthread_mutex_unlock(&obj->lock);
    pthread_cond_signal(&obj->second_print);
}

void third(Foo* obj) {

    // printThird() outputs "third". Do not change or remove this line.
    pthread_mutex_lock(&obj->lock);
    while(obj->cnt < 2) {
        pthread_cond_wait(&obj->second_print, &obj->lock);
    }
    pthread_mutex_unlock(&obj->lock);
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    pthread_mutex_destroy(&obj->lock);
    pthread_cond_destroy(&obj->first_print);
    pthread_cond_destroy(&obj->second_print);
    free(obj);
}

int main()
{
    return 0;
}
