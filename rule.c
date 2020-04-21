#include "rule.h"

#define abs(v) (v > 0.0 ? v : -v)

/* OTHER RULES BEGIN *********************************************************/

static const int redFades = 3;

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
    double n;

    fx /= pow (2.0, fframe * redFades);
    fy /= pow (2.0, fframe * redFades);
    
    n = floor (log (abs (fy)) / log (2.0));

    for (i = 0; i < 256; ++i, ++n) {
        r = pow (2.0, n);

        if (pow (fmod (abs (fx), 2.0 * r) - r, 2.0) + pow (fy, 2.0) <= pow (r, 2.0)) {
            break;
        }
    }

    pixel[0] = fmod (n / redFades, 1.0) * 255;
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