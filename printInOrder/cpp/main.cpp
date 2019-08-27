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
#include <mutex>
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

#include "input.hpp"

#define wl(n) while(n--)
#define min(a,b) a < b ? a : b
#define max(a,b) a < b ? b : a
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

class Foo {
    mutex second_mutex, third_mutex;
public:
    Foo(): second_mutex(mutex()), third_mutex(mutex()) {
        second_mutex.lock();
        third_mutex.lock();
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        second_mutex.unlock();
    }

    void second(function<void()> printSecond) {

        // printSecond() outputs "second". Do not change or remove this line.
        second_mutex.lock();
        printSecond();
        second_mutex.unlock();
        third_mutex.unlock();
    }

    void third(function<void()> printThird) {

        // printThird() outputs "third". Do not change or remove this line.
        third_mutex.lock();
        printThird();
        third_mutex.unlock();
    }
};

int main()
{
    return 0;
}
