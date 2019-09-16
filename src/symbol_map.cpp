//
// Created by alice on 9/15/19.
//

#include "symbol_map.h"
#include "image_io.h"
#include "image_manipulation.h"

SymbolMap::SymbolMap(std::string font_path, std::string symbols) {
    generate_character_images((char *) font_path.c_str(), symbols);
    luminance_map = get_luminance_map(symbols);
}

std::string SymbolMap::get_closest_symbol(double luminance) {
    if (luminance == 0)
        return std::string("  ");
    else
        return luminance_map.lower_bound(luminance)->second;
}
