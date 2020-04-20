#include <stdio.h>
#include <stdlib.h>

#include "lodepng.h"
#include "config.h"

#include "rule.h"

int main (void) {
    unsigned char *map = (unsigned char*) malloc (width * height * channels);
    int iframe, index, ix, iy;
    double fframe, fx, fy;
    double fxStart = -1.0;
    double fframeStep = 1.0 / frames, fxStep = 2.0 / width, fyStep = 2.0 / height;
    unsigned int error;
    char filename[260];
    double faspectRatio = 1.0;

    if (aspect) {
        faspectRatio = (double) height / width;
        fxStep /= faspectRatio;
        fxStart /= faspectRatio;
    }

    for (iframe = 0; iframe < frames; ++iframe, fframe += fframeStep) {
        index = 0;
        
        for (iy = 0, fy = -1.0; iy < height; ++iy, fy += fyStep) {
            for (ix = 0, fx = fxStart; ix < width; ++ix, fx += fxStep, index += channels) {
                rule (
                    map,
                    iframe,
                    fframe,
                    &map[index],
                    ix, iy,
                    fx, fy
                );
            }
        }

        sprintf (filename, "%s/%s%08d.png", dir, prefix, iframe);
        
        error = lodepng_encode32_file (filename, map, width, height);
        
        if (error) {
            printf ("error %u: %s\n", error, lodepng_error_text (error));
            break;
        }
    }

    free (map);
    return 0;
}