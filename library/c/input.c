#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"

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

int myPartition(int* a, int l, int h) {
    int p = a[h], i = l;
    for(int j = l ; j < h ; ++j) {
        if (a[j] < p) {
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
            ++i;
        }
    }
    int tmp = a[h];
    a[h] = a[i];
    a[i] = tmp;
    return i;
}

void myQuicksort(int* a, int l, int h) {
    if(l < h) {
        int p = myPartition(a, l, h);
        myQuicksort(a, p + 1, h);
        myQuicksort(a, l, p - 1);
    }
}

