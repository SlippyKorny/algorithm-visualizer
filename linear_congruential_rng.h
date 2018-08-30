#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "terminal_colors.h"

int lin_cngr(int a, int c, int m, int *seed)
{
    *seed = (*seed * a + c) % m;
    return *seed;
}

void lin_con_to_ppm(const int dim_x, const int dim_y)
{
    // Modulus 2^31
    int a = 1103515245; // multiplier
    int c = 12345; // increment
    int m = (int)pow(2, 31);
    int seed = 1;
//    int *seed_ptr = &seed;

    printf("[Creating the file (lin_con_to_ppm)]\r\n");
    FILE * fp = fopen("linear_congruential.ppm", "wb");
    if (fp == NULL)
        printf(ANSI_COLOR_RED "[An error occured - cannot create the file (lin_con_to_ppm)]" ANSI_COLOR_RESET);
    fprintf(fp, "P6\n%d %d\n255\n", dim_x, dim_y);
    printf("[Generating the image (lin_con_to_ppm)]\r\n");
    unsigned char color[3];
    for (int i=0; i < dim_x; i++)
    {
        for (int j=0; j < dim_y; j++)
        {
            color[0] = (unsigned char)(lin_cngr(a, c, m, &seed)%255);
            color[1] = (unsigned char)(lin_cngr(a, c, m, &seed)%255);
            color[2] = (unsigned char)(lin_cngr(a, c, m, &seed)%255);
            fwrite(color,1,3,fp);
        }
    }
    printf("[Closing the buffer (lin_con_to_ppm)]\r\n");
    fclose(fp);
}