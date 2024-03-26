cmake_minimum_required(VERSION 3.28)

add_library(glad STATIC winglad.h winglad.cpp glad/glad.h glad/glad.c)
add_library(lib::glad ALIAS glad)

#out variable for parent
set(GLAD_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(GLAD_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
set(GLAD_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(GLAD_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib PARENT_SCOPE)

#set build out files
if(DEFINED LIB_DIR)
    message(STATUS "glob on")
    set(GLAD_LIB_DIR ${LIB_DIR})
    set(GLAD_LIB_DIR ${LIB_DIR} PARENT_SCOPE)
endif()

message(STATUS "GLAD_INC_DIR : ${GLAD_INC_DIR}")
message(STATUS "GLAD_LIB_DIR : ${GLAD_LIB_DIR}")

set_target_properties(glad  PROPERTIES
    INCLUDE_DIRECTORIES ${GLAD_INC_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${GLAD_LIB_DIR}
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${GLAD_LIB_DIR}
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${GLAD_LIB_DIR})



