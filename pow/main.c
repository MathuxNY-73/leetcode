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

double myPow(double x, int n) {
    long n_l = n;

    if(n_l < 0)
    {
        x = 1/x;
        n_l *= -1;
    }

    printf("%ld\n", n_l);

    double res = 1;
    double cur = x;
    for(long i = n_l ; i > 0 ; i >>= 1)
    {
        if(i % 2 == 1)
        {
            res = res * cur;
        }
        cur = cur * cur;
    }

    return res;
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

void fastscan_double(double* number)
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

    if(c == '.' || c == ',')
        for (c=getchar_unlocked(); (c>47 && c<58); c=getchar_unlocked())
            *number = *number + (c - 48) / (double)10;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        *number *= -1;
}

int main()
{
    int t = 0;
    fastscan(&t);

    wl(t)
    {
        double x = 0;
        fastscan_double(&x);
        int n = 0;
        fastscan(&n);

        double result = myPow(x, n);

        printf("%lf\n", result);
    }

    return 0;
}
