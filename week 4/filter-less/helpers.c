#include "helpers.h"
#include <stdlib.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
                RGBTRIPLE *pixel = &image[i][j];
                int avg = round((pixel->rgbtRed + pixel->rgbtGreen + pixel->rgbtBlue) / 3.0);
                pixel->rgbtRed = avg;
                pixel->rgbtGreen = avg;
                pixel->rgbtBlue = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            RGBTRIPLE *pixel = &image[i][j];
            RGBTRIPLE originalPixel = image[i][j];
            pixel->rgbtRed = round(0.393* originalPixel.rgbtRed + 0.769 * originalPixel.rgbtGreen + 0.189 * originalPixel.rgbtBlue);
            pixel->rgbtGreen = round(0.349* originalPixel.rgbtRed  + 0.686 * originalPixel.rgbtGreen + 0.168 * originalPixel.rgbtBlue);
            pixel->rgbtBlue = round(0.272* originalPixel.rgbtRed + 0.534 * originalPixel.rgbtGreen + 0.131 * originalPixel.rgbtBlue);

            if (pixel->rgbtRed > 255) {
                pixel->rgbtRed = 255;
            }
            if (pixel->rgbtGreen > 255) {
                pixel->rgbtGreen = 255;
            }
            if (pixel->rgbtBlue > 255) {
                pixel->rgbtBlue = 255;
            }
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width / 2; ++j) {
                RGBTRIPLE *pixel = &image[i][j];
                RGBTRIPLE *pixel2 = &image[i][width - j - 1];
                RGBTRIPLE temp = *pixel;
                *pixel = *pixel2;
                *pixel2 = temp;
            }
        }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE (*image2)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (image2 == NULL)
    {
        return;
    }

    //blur
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; j++) {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 0;
            for (int k = -1; k < 2; ++k) {
                for (int l = -1; l < 2; ++l) {
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width) {
                        sumRed += image[i + k][j + l].rgbtRed;
                        sumGreen += image[i + k][j + l].rgbtGreen;
                        sumBlue += image[i + k][j + l].rgbtBlue;
                        count++;
                    }
                }
            }
            image2[i][j].rgbtRed = sumRed / count;
            image2[i][j].rgbtGreen = sumGreen / count;
            image2[i][j].rgbtBlue = sumBlue / count;
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            image[i][j] = image2[i][j];
        }
    }

    free(image2);
    return;
}
