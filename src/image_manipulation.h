//
// Created by alice on 9/15/19.
//

#ifndef ASCIITEST_IMAGE_MANIPULATION_H
#define ASCIITEST_IMAGE_MANIPULATION_H

#include <vector>
#include <png++/png.hpp>

typedef std::vector<std::vector<double>> image_vec;
typedef png::image<png::rgb_pixel> rgb_image;

image_vec compress_vector(const rgb_image &image, int factor);
void print_row(const std::vector<double> &row);
double luminance(png::rgb_pixel pixel);
double luminance(double r, double g, double b);

#endif //ASCIITEST_IMAGE_MANIPULATION_H
