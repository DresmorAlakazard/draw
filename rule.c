#include "rule.h"

#include <math.h>

void rule (
    unsigned char *map,
    int iframe,
    double fframe,
    unsigned char *pixel,
    int ix, int iy,
    double fx, double fy
) {
    double x = fx * 5.0;
    double y = fy * 5.0;

    #if 0
    int pass = 1;
    #else
    double x0 = fmod (fabs (x), 2.0) - 1.0;
    double y0 = fmod (fabs (y), 2.0) - 1.0;

    double nx = fmod (fabs (x), 2.0) < 1.0 ? 1.0 : -1.0;
    double ny = fmod (fabs (y), 2.0) < 1.0 ? 1.0 : -1.0;

    double x1 = fmod (fabs ((x0 * nx) + 1.0), 1.0);
    double y1 = fmod (fabs ((y0 * ny) + 1.0), 1.0);

    double x2 = fmod (fabs ((x0 * nx) - 1.0), 1.0);
    double y2 = fmod (fabs ((y0 * ny) - 1.0), 1.0);

    int pass = x1 * x1 + y1 * y1 <= 0.5 || x2 * x2 + y2 * y2 <= 0.5;
    #endif

    if (pass) {
        pixel[0] = 255;
        pixel[3] = 255;
    } else {
        pixel[3] = 0;
    }

    #if 0
    if ((x < 1.05 && x > 0.95) || (y < 1.05 && y > 0.95)) {
        pixel[2] = 255;
        pixel[3] = 255;
    }

    if ((x < 0.05 && x > -0.05) || (y < 0.05 && y > -0.05)) {
        pixel[2] = 255;
        pixel[1] = 255;
        pixel[3] = 255;
    }
    #endif
}