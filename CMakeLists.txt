cmake_minimum_required(VERSION 3.12)
project(asciitest)

set(CMAKE_CXX_STANDARD 17)

add_executable(asciitest src/main.cpp src/image_manipulation.cpp src/image_manipulation.h src/symbol_map.cpp src/symbol_map.h src/image_io.cpp src/image_io.h)

find_package(PNG REQUIRED)
find_package(PNGwriter 0.7.0)

target_link_libraries(asciitest PRIVATE PNGwriter::PNGwriter ${PNG_LIBRARY})