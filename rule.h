#ifndef RULE_H
#define RULE_H

void rule (
    unsigned char *map,
    int iframe,
    double fframe,
    unsigned char *pixel,
    int ix, int iy,
    double fx, double fy
) {
    if (fx * fx + fy * fy <= 1.0) {
        pixel[0] = 255;
        pixel[3] = 255;
    } else {
        pixel[3] = 0;
    }
}

#endif