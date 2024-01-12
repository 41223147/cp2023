#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_roc_flag(gdImagePtr img);
void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color);
void findIntersectPoints(int center_x, int center_y, int radius, int i, gdPoint *points);

int main() {
    int width = 1200;
    int height = (int)(width * 2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_roc_flag(img);

    FILE *outputFile = fopen("roc_flag_in_gd.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_roc_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, white, blue;
    int center_x = (int)(width / 4);
    int center_y = (int)(height / 4);

    red = gdImageColorAllocate(img, 255, 0, 0);
    white = gdImageColorAllocate(img, 255, 255, 255);
    blue = gdImageColorAllocate(img, 0, 0, 149);

    gdImageFilledRectangle(img, 0, 0, width, height, red);
    gdImageFilledRectangle(img, 0, 0, (int)(width / 2.0), (int)(height / 2.0), blue);

    int sun_radius = (int)(width / 8);
    draw_white_sun(img, center_x, center_y, sun_radius, white);
}

void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color) {
    float deg = M_PI / 180;
    float sr = sun_radius / tan(75 * deg);
    gdPoint points[4];

    for (int i = 1; i <= 6; i++) {
        findIntersectPoints(center_x, center_y, sun_radius, i, points);
        gdImageLine(img, points[0].x, points[0].y, points[1].x, points[1].y, color);

        findIntersectPoints(center_x, center_y, sr, i, points);
        gdImageLine(img, points[1].x, points[1].y, points[2].x, points[2].y, color);

        findIntersectPoints(center_x, center_y, sun_radius, i + 1, points);
        gdImageLine(img, points[2].x, points[2].y, points[3].x, points[3].y, color);

        findIntersectPoints(center_x, center_y, sr, i + 1, points);
        gdImageLine(img, points[3].x, points[3].y, points[0].x, points[0].y, color);
    }
}

void findIntersectPoints(int center_x, int center_y, int radius, int i, gdPoint *points) {
    float deg = M_PI / 180;
    float angle = 30 * i * deg;

    points[0].x = center_x + radius * sin(angle);
    points[0].y = center_y - radius + radius * cos(angle);

    points[1].x = center_x + radius * sin(angle + 30 * deg);
    points[1].y = center_y - radius + radius * cos(angle + 30 * deg);

    points[2].x = center_x + radius * sin(angle + 60 * deg);
    points[2].y = center_y - radius + radius * cos(angle + 60 * deg);

    points[3].x = center_x + radius * sin(angle + 90 * deg);
    points[3].y = center_y - radius + radius * cos(angle + 90 * deg);
}