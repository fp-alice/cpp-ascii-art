#include <iostream>
#include <vector>
#include "png++/png.hpp"
#include "image_manipulation.h"
#include "image_io.h"
#include <pngwriter.h>
#include <iterator>
#include <sstream>
#include <map>
#include "symbol_map.h"

int main() {
    rgb_image image("../star.png");
    image_vec compressed = compress_vector(image, 8);

    std::string path("../font/roboto_mono.ttf");
    std::string symbols("*=-_+./,@#!$%^&0");

    SymbolMap symbolMap = SymbolMap(path, symbols);

    for (auto row : compressed) {
        for (auto luminance : row) {
            std::cout << symbolMap.get_closest_symbol(luminance);
        }
        std::cout << std::endl;
    }

    return 0;
}