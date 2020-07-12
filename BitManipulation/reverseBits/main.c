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

#define MAX 0x7FFFFFFF

int reverseByte(uint32_t byte) {
    int byte_rev[256];
    memset(byte_rev, 0, sizeof(int) * 256);

    if(!byte) {
        return 0;
    }
    else if (byte_rev[byte] == 0) {
        byte_rev[byte] = ((uint32_t)byte * 0x0202020202 & 0x010884422010) % 1023;
    }
    return byte_rev[byte];
}


uint32_t reverseBits(uint32_t n) {
    int power = 24;

    uint32_t res = 0;
    while (n) {
        res += ((uint32_t)reverseByte(n & 0xff)) << power;
        n >>= 8;
        power -= 8;
    }

    return res;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        char buf[33];
        memset(buf, '\0', sizeof(char) * 33);
        fastscan_string_w(buf, 32);

        uint32_t n = 0;
        for(int i = 0 ; i < 32 ; ++i) {
            n += ((uint32_t)(buf[i] == '1') << i);
        }

        uint32_t res = reverseBits(n);

        for(int i = 31 ; i >= 0 ; --i) {
            buf[i] = (res & (1 << i)) ? '1' : '0';
        }

        printf("%s\n", buf);
    }
    return 0;
}
