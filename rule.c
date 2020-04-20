#include "rule.h"

static void triangles (
    unsigned char *map,
    int iframe,
    double fframe,
    unsigned char *pixel,
    int ix, int iy,
    double fx, double fy
) {
    fx *= 100.0;
    fy *= 100.0;
    
    double v = fabs (fmod (fabs (fx + fmod (floor (fy + (fy > 0.0 ? 0.0 : 1.0)), 2.0)), 2.0) - 1.0);
    double u = fmod (fabs (fy), 1.0);

    if (fy > 0.0 ? v > u : v < u) {
        pixel[0] = 255;
    }

    /* "Help center..." */
    #if 0
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