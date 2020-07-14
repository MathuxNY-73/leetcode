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

#define SIZE 1001

double angleClock(int hour, int minutes){
    const double angle_per_minute = 6;
    const double angle_per_hour = 0.5;

    double min_angle = minutes * angle_per_minute;
    double hour_angle = (double)((hour % 12) * 30) + (double)(minutes) * angle_per_hour;

    double comp = fabs(min_angle - hour_angle);

    if (comp > 180) {
        return 360 - comp;
    }
    return comp;
}

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int hours = 0, minutes = 0;
        fastscan(&hours);
        fastscan(&minutes);

        double res = angleClock(hours, minutes);
        printf("%lf\n", res);
    }
    return 0;
}
