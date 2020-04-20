#ifndef RULE_H
#define RULE_H

#include <math.h>

#define abs(v) (v > 0.0 ? v : -v)
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

/* OTHER RULES BEGIN *********************************************************/

static void xcpara (
    unsigned char *map,
    int iframe,
    double fframe,
    unsigned char *pixel,
    int ix, int iy,
    double fx, double fy
) {
    int i;
    double r;
    double n = floor (log (abs (fy)) / log (2.0));

    for (i = 0; i < 256; ++i, ++n) {
        r = pow (2.0, n);

        if (pow (fmod (abs (fx), 2.0 * r) - r, 2.0) + pow (fy, 2.0) <= pow (r, 2.0)) {
            break;
        }
    }

    pixel[0] = fmod (n / 5.0, 1.0) * 255;
}

/* OTHER RULES END ***********************************************************/

void rule (
    unsigned char *map,
    int iframe,
    double fframe,
    unsigned char *pixel,
    int ix, int iy,
    double fx, double fy
) {
    pixel[0] = 0;
    pixel[1] = 0;
    pixel[2] = 0;
    pixel[3] = 255;

    xcpara (map, iframe, fframe, pixel, ix, iy, fx, fy);
}

#endif