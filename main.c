#include <stdio.h>
#include <time.h>
#include <string.h>

#include "terminal_colors.h"
#include "middle_square_rng.h"
#include "linear_congruential_rng.h"
#include "perlin_noise.h"

void rand_to_ppm(const int dim_x, const int dim_y)
{
    int i, j;
    printf("[Creating the file (rand_to_ppm)]\r\n");
    FILE * fp = fopen("rand.ppm", "wb");
    if (fp == NULL)
        printf(ANSI_COLOR_RED "[An error occured - cannot create the file (rand_to_ppm)]" ANSI_COLOR_RESET);
    fprintf(fp, "P6\n%d %d\n255\n", dim_x, dim_y);
    printf("[Generating the image (middle_square_to_ppm)]\r\n");
    for(j=0; j<dim_y; ++j)
    {
        for(i=0; i<dim_x; ++i)
        {
            static unsigned char color[3];
            color[0]= (unsigned char) (rand() % 255); /* red */
            color[1]= (unsigned char) (rand() % 255); /* green */
            color[2]= (unsigned char) (rand() % 255); /* blue */
            fwrite(color,1,3,fp);
        }
    }
    printf("[Closing the buffer (middle_square_to_ppm)]\r\n");
    fclose(fp);
}

int main(int argc, const char **argv)
{
    // TODO: Maybe make a "time-elapsed" thingy
//    if (argc == 1)
//        return 0;
//    else if (argc > 1)
//    {
//        if(!strcmp(argv[1], "rand"))
//            rand_to_ppm(255, 255);
//        else if(!strcmp(argv[1], "middle_square"))
//            middle_square_to_ppm(255, 255);
//        else if(!strcmp(argv[1], "linear_congruential"))
//            lin_con_to_ppm(255, 255);
//        else
//            lin_con_to_ppm(255, 255);
//    }
    perlin_noise_to_ppm(255, 255);
    return 0;
}
