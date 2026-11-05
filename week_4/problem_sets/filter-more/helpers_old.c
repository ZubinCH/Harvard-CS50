#include "helpers.h"
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
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
            image[i][j] = image[i][width - 1 - j];
            image[i][width - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < width - 1; j++) {
            int Rsum = 0, Gsum = 0, Bsum = 0, n = 0;

            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (k < 0 || l < 0 || k >= height || l >= width) continue;

                    Rsum += image[k][l].rgbtRed;
                    Gsum += image[k][l].rgbtGreen;
                    Bsum += image[k][l].rgbtBlue;
                    n++;
                }
            }

            int rAverage = Rsum / n, gAverage = Gsum / n, bAverage = Bsum / n;

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
            int A_red[ROWS][COLUMNS];
            int A_green[ROWS][COLUMNS];
            int A_blue[ROWS][COLUMNS];

            for (int k = 0; k < ROWS; k++) {
                for (int l = 0; l < COLUMNS; l++) {
                    if (i - 1 + k < 0 || j - 1 + l < 0 || i - 1 + k >= height || j - 1 + l >= width) {
                        A_red[k][l] = 0;
                        A_green[k][l] = 0;
                        A_blue[k][l] = 0;
                    }

                    else {
                        A_red[k][l] = image[i - 1 + k][j - 1 + l].rgbtRed;
                        A_green[k][l] = image[i - 1 + k][j - 1 + l].rgbtGreen;
                        A_blue[k][l] = image[i - 1 + k][j - 1 + l].rgbtBlue;
                    }
                }
            }


            int Gx_red[ROWS][COLUMNS];
            int Gy_red[ROWS][COLUMNS];
            mcopy(ROWS, COLUMNS, Gx_red, A_red);
            mcopy(ROWS, COLUMNS, Gy_red, A_red);
            mmultiply(ROWS, COLUMNS, Gx, Gx_red);
            mmultiply(ROWS, COLUMNS, Gy, Gy_red);
            int Gred = abs(mdet(ROWS, COLUMNS, Gx_red)) + abs(mdet(ROWS, COLUMNS, Gy_red));
            if (Gred > 255) Gred = 255;
            else if (Gred < 0) Gred = 0;
            image[i][j].rgbtRed = Gred;

            int Gx_green[ROWS][COLUMNS];
            int Gy_green[ROWS][COLUMNS];
            mcopy(ROWS, COLUMNS, Gx_green, A_green);
            mcopy(ROWS, COLUMNS, Gy_green, A_green);
            mmultiply(ROWS, COLUMNS, Gx, Gx_green);
            mmultiply(ROWS, COLUMNS, Gy, Gy_green);
            int Ggreen = abs(mdet(ROWS, COLUMNS, Gx_green)) + abs(mdet(ROWS, COLUMNS, Gy_green));
            if (Ggreen > 255) Ggreen = 255;
            else if (Ggreen < 0) Ggreen = 0;
            image[i][j].rgbtGreen = Ggreen;

            int Gx_blue[ROWS][COLUMNS];
            int Gy_blue[ROWS][COLUMNS];
            mcopy(ROWS, COLUMNS, Gx_blue, A_blue);
            mcopy(ROWS, COLUMNS, Gy_blue, A_blue);
            mmultiply(ROWS, COLUMNS, Gx, Gx_blue);
            mmultiply(ROWS, COLUMNS, Gy, Gy_blue);
            int Gblue = abs(mdet(ROWS, COLUMNS, Gx_blue)) + abs(mdet(ROWS, COLUMNS, Gy_blue));
            if (Gblue > 255) Gblue = 255;
            else if (Gblue < 0) Gblue = 0;
            image[i][j].rgbtBlue = Gblue;

        }






    }




    return;
}


void mcopy(int rows, int columns, int matrixA[rows][columns], int matrixB[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrixA[i][j] = matrixB[i][j];
        }
    }

}

void mmultiply(int rows, int columns, int matrixA[rows][columns], int matrixB[rows][columns]) {
    
    int Mresult[rows][columns];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int sum = 0;
            for (int k = 0; k < columns; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            Mresult[i][j] = sum;
        }
    }

    mcopy(rows, columns, matrixB, Mresult);

}

int mdet(int rows, int columns, int A[rows][columns]) {
    int result1 = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]);
    int result2 = A[0][1] * (A[1][2] * A[2][0] - A[1][0] * A[2][2]);
    int result3 = A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

    return result1 + result2 + result3;
}