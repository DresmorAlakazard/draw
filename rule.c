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
    double x = fx * (144.0 / 8.0);
    double y = fy * (144.0 / 8.0);

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

    int pass = x1 * x1 + y1 * y1 <= 0.375 || x2 * x2 + y2 * y2 <= 0.375;
    #endif

    if (pass) {
        pixel[0] = 255;
        pixel[1] = 200;
        pixel[2] = 48;
        pixel[3] = 255;
    } else {
        pixel[0] = 204;
        pixel[1] = 150;
        pixel[2] = 0; /* (1.0 / pow (fabs (x), fabs (y))) * 20.0; */
        pixel[3] = 255;
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