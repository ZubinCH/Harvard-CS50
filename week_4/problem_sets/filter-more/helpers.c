#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int average = round(
                ((double) image[i][j].rgbtBlue + (double) image[i][j].rgbtGreen
                 + (double) image[i][j].rgbtRed) / 3
                );
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int Rsum = 0, Gsum = 0, Bsum = 0, n = 0;

            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (k < 0 || l < 0 || k >= height || l >= width) continue;

                    Rsum += copy[k][l].rgbtRed;
                    Gsum += copy[k][l].rgbtGreen;
                    Bsum += copy[k][l].rgbtBlue;
                    n++;
                }
            }

            int rAverage = round((double) Rsum / n);
            int gAverage = round((double) Gsum / n);
            int bAverage = round((double) Bsum / n);

            image[i][j].rgbtRed = rAverage;
            image[i][j].rgbtGreen = gAverage;
            image[i][j].rgbtBlue = bAverage;

        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    #define ROWS 3
    #define COLUMNS 3
    RGBTRIPLE (*copy)[width] = calloc(height, sizeof(RGBTRIPLE[width]));
    if (!copy) return;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }


    int Gx[ROWS][COLUMNS] = {
        {-1, 0, 1}, 
        {-2, 0, 2}, 
        {-1, 0, 1}
    };

    int Gy[ROWS][COLUMNS] = {
        {-1, -2, -1}, 
        {0, 0, 0}, 
        {1, 2, 1}
    };

    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int Ax_red = 0;
            int Ax_green = 0;
            int Ax_blue = 0;

            int Ay_red = 0;
            int Ay_green = 0;
            int Ay_blue = 0;

            for (int k = 0; k < ROWS; k++) {
                for (int l = 0; l < COLUMNS; l++) {
                    if (i - 1 + k < 0 || j - 1 + l < 0 || i - 1 + k >= height || j - 1 + l >= width) continue;
                    
                    Ax_red += copy[i - 1 + k][j - 1 + l].rgbtRed * Gx[k][l];
                    Ay_red += copy[i - 1 + k][j - 1 + l].rgbtRed * Gy[k][l];
                    
                    Ax_green += copy[i - 1 + k][j - 1 + l].rgbtGreen * Gx[k][l];
                    Ay_green += copy[i - 1 + k][j - 1 + l].rgbtGreen * Gy[k][l];

                    Ax_blue += copy[i - 1 + k][j - 1 + l].rgbtBlue * Gx[k][l];
                    Ay_blue += copy[i - 1 + k][j - 1 + l].rgbtBlue * Gy[k][l];

                }
            }

            int Gred = round(sqrt(Ax_red * Ax_red + Ay_red * Ay_red));
            int Ggreen = round(sqrt(Ax_green * Ax_green + Ay_green * Ay_green));
            int Gblue = round(sqrt(Ax_blue * Ax_blue + Ay_blue * Ay_blue));


            if (Gred > 255) Gred = 255;
            if (Ggreen > 255) Ggreen = 255;
            if (Gblue > 255) Gblue = 255;


            image[i][j].rgbtRed = Gred;
            image[i][j].rgbtGreen = Ggreen;
            image[i][j].rgbtBlue = Gblue;

        }
    }



    free(copy);
    return;
}


void invert(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].rgbtBlue = 255 - image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = 255 - image[i][j].rgbtGreen;
            image[i][j].rgbtRed = 255 - image[i][j].rgbtRed;

        }
    }

    return;
}

