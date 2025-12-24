#include "vec3.h"
#include "color.h"

#include <stdio.h>

int main(void)
{
    /* Image */
    int image_width = 256;
    int image_height = 256;

    /* PPM header */
    printf("P3\n%d %d\n255\n", image_width, image_height);

    /* Render */
    for (int j = 0; j < image_height; j++)
    {
        /* Progress indicator (stderr, same role as std::clog) */
        fprintf(stderr, "\rScanlines remaining: %d ", image_height - j);
        fflush(stderr);

        for (int i = 0; i < image_width; i++)
        {
            color pixel_color = vec3_create(
                (double)i / (image_width - 1),
                (double)j / (image_height - 1),
                0.0
            );

            write_color(stdout, pixel_color);
        }
    }

    fprintf(stderr, "\rDone.                 \n");
    return 0;
}
