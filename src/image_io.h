//
// Created by alice on 9/15/19.
//

#ifndef ASCIITEST_IMAGE_IO_H
#define ASCIITEST_IMAGE_IO_H

#include <string>
#include <map>

void create_character_image(char *font, char *c);

void generate_character_images(char *font, std::string symbols);

double get_character_luminance(char *c);

double get_character_luminance(const std::string &c);

std::map<double, std::string> get_luminance_map(const std::string &symbols);

#endif //ASCIITEST_IMAGE_IO_H
