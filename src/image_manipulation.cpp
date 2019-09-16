//
// Created by alice on 9/15/19.
//

#include <pngwriter.h>
#include "image_manipulation.h"

double luminance(double r, double g, double b) {
    return (0.2125 * r) + (0.7152 * g) + (0.0722 * b);
}

double luminance(png::rgb_pixel pixel) {
    return luminance(pixel.red, pixel.green, pixel.blue);
}

image_vec compress_vector(const rgb_image &image, int factor) {
    png::uint_32 width = image.get_height();
    png::uint_32 height = image.get_height();

    auto compress_row = [&](unsigned long y) {
        std::vector<double> result;
        for (unsigned long j = 0; j < width; j += factor) {
            double square_sum = 0;
            for (unsigned long x = j; x < j + factor; x++) {
                square_sum += luminance(image[y][x]);
            }
            result.push_back(square_sum / (factor * factor));
        }
        return result;
    };

    std::vector<std::vector<double>> compressed_rows;
    for (unsigned long i = 0; i < height; i += factor) {
        compressed_rows.push_back(compress_row(i));
    }
    return compressed_rows;
}

void print_row(const std::vector<double> &row) {
    int i = 0;
    for (auto x : row) {

        if (i == 0) std::cout << "[";

        char s[4];
        snprintf(s, 4, "%3d", (int) x);

        const char *end;

        if (i == row.size() - 1) {
            end = "]";
        } else {
            end = ", ";
        }

        std::cout << s << end;
        i++;
    }
    std::cout << std::endl;
}