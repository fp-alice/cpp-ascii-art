//
// Created by alice on 9/15/19.
//

#include <pngwriter.h>
#include <algorithm>
#include "image_io.h"
#include "image_manipulation.h"

void create_character_image(char *font, char *c) {
    char path[16];
    sprintf(path, "../chars/%s.png", c);
    pngwriter image(34, 50, 1.0, path);
    image.plot_text(font, 40, 0, 8, 0, c, 255, 255, 255);
    image.close();
}

double get_character_luminance(char *c) {
    char path[15];
    sprintf(path, "../chars/%s.png", c);
    rgb_image image(path);

    double sum = 0;

    for (int i = 0; i < image.get_width(); ++i) {
        for (int j = 0; j < image.get_height(); ++j) {
            sum += luminance(image[i][j]);
        }
    }

    return 255 - (sum / (image.get_height() * image.get_width()));
}

double get_character_luminance(const std::string &c) {
    return get_character_luminance((char *)c.c_str());
}

std::vector<std::string> split_string(std::string string) {
    std::vector<std::string> strings;
    for (char c : string) {
        std::string str(2, c);
        strings.push_back(str);
    }
    return strings;
}

std::map<double, std::string> normalize_map(std::map<double, std::string> map) {
    auto min_pair = std::min_element(std::begin(map), std::end(map), [](const auto& l, const auto& r) { return l.second < r.second; });

    auto it = map.begin();

    std::map<double, std::string> normalized_map;

    while (it != map.end()) {
        auto index = std::max(it->first - min_pair->first, 0.0);
        normalized_map[index] = it->second;
        it++;
    }

    return normalized_map;
}

std::map<double, std::string> get_luminance_map(const std::string &symbols) {
    std::map<double, std::string> map;
    for (const auto &symbol : split_string(symbols)) {
        auto l = get_character_luminance(symbol);
        map[l] = symbol;
    }

    return normalize_map(map);
}


void generate_character_images(char *font, std::string symbols) {
    for (const auto &symbol : split_string(symbols)) {
        create_character_image(font, (char *)symbol.c_str());
    }
}