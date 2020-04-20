#include "rule.h"

static void triangles (
    unsigned char *map,
    int iframe,
    double fframe,
    unsigned char *pixel,
    int ix, int iy,
    double fx, double fy
) {
    fx *= 4.0;
    fy *= 4.0;

    double v = fmod (fabs (fx), 2.0);
    double u = fy;

    double tmp = v - u;

    if (tmp < .1 && tmp > -.1) {
        pixel[0] = 255;
    }

    /* "Help center..." */
    #if 1
    if (fy < 1.1 && fy > 0.9 && fx < 1.1 && fx > 0.9) {
        pixel[2] = 255;
    }

    if (fy < 0.1 && fy > -0.1) {
        pixel[2] = 255;
    }

    if (fx < 0.1 && fx > -0.1) {
        pixel[1] = 255;
    }
    #endif
}

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

    triangles (map, iframe, fframe, pixel, ix, iy, fx, fy);
}