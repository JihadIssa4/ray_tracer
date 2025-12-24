#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <stdio.h>

/*
 * color is just an alias for vec3
 */
typedef vec3 color;

/*
 * Write a color to an output stream (PPM format style)
 */
static inline void write_color(FILE *out, color pixel_color)
{
    double r = pixel_color.e[0];
    double g = pixel_color.e[1];
    double b = pixel_color.e[2];

    /* Translate the [0,1] range to [0,255] */
    int rbyte = (int)(255.999 * r);
    int gbyte = (int)(255.999 * g);
    int bbyte = (int)(255.999 * b);

    /* Write pixel color */
    fprintf(out, "%d %d %d\n", rbyte, gbyte, bbyte);
}

#endif
