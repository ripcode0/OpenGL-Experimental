cmake_minimum_required(VERSION 3.28)

#set glad
set(INSTALL_GLAD_DIR ${CMAKE_SOURCE_DIR}/External/glad)

if(NOT EXISTS ${INSTALL_GLAD_DIR})
    message(STATUS "install glad")
    
endif()

#set stb image library

