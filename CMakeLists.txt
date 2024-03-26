cmake_minimum_required(VERSION 3.28)

project(OpenGL-Experimetal)

#globar variable
set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
set(INC_DIR ${CMAKE_SOURCE_DIR}/External)   #append able

#build libs
include(buildLib.cmake)

#build excutable
add_subdirectory(Sample/01-Window)

