//
// Created by alice on 9/15/19.
//

#ifndef ASCIITEST_SYMBOL_MAP_H
#define ASCIITEST_SYMBOL_MAP_H


#include <string>
#include <map>

class SymbolMap {
public:
    explicit SymbolMap(std::string font_path, std::string symbols);
    std::string get_closest_symbol(double luminance);
private:
    std::map<double, std::string> luminance_map;
};


#endif //ASCIITEST_SYMBOL_MAP_H
