#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#include "terminal_colors.h"


unsigned char ms_rng_(unsigned char seed)
{
    int buffer = (int)pow(seed, 2);
    int beggining = buffer/10000;
    int b[3];
    b[0] = buffer - (beggining * 10000); // 4516
    b[1] = b[0] - (b[0]/1000) * 1000;
    b[2] = b[1] - (b[1]/100) * 100;
    int ending = b[2] - (b[2]/10) * 10;
    int asida = (beggining * 10) + ending;
    return (unsigned char) (asida);
}

unsigned char ms_rng(unsigned char seed)
{
    int buffer = (int)pow(seed, 2);
    int beggining = buffer/1000;
    int b[2];
    b[0] = buffer - (beggining * 1000);
    b[1] = b[0] - (b[0] * 100) * 100;
    int ending = b[1] - (b[1]/10) * 10;
    int asida = (beggining * 10) + ending;
    return (unsigned char) (asida);
}

void middle_square_to_ppm(const int dim_x, const int dim_y)
{
    unsigned char entry_seed = rand()%255;
    FILE * fp = fopen("middle_square.ppm", "wb");
    if (fp == NULL)
        printf(ANSI_COLOR_RED "[An error occured - cannot create the file (rand_to_ppm)]" ANSI_COLOR_RESET);
    fprintf(fp, "P6\n%d %d\n255\n", dim_x, dim_y);
    unsigned char color[3];

    for (int i=0; i < dim_x; i++)
    {
        for (int j=0; j < dim_y; j++)
        {
            if (i != 0 && j != 0)
                color[0] = ms_rng(color[2]); /* red */
            else
                color[0] = ms_rng_(entry_seed);
            printf("R: %i ", color[0]);
            color[1] = ms_rng(color[0]);
            printf("G: %i ", color[1]);
            color[2] = ms_rng(color[1]);
            printf("B: %i\r\n", color[2]);
            fwrite(color,1,3,fp);
        }
    }
    fclose(fp);
}
