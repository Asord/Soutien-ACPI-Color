cmake_minimum_required(VERSION 3.10)
project(color_slp)

set(CMAKE_CXX_STANDARD 14)

add_executable(color_slp main.cpp tools/AsMath.h tools/lodepng.cpp tools/lodepng.h classes/PNG.cpp classes/PNG.h classes/Color.cpp classes/Color.h classes/Editor.h classes/Editor.cpp)