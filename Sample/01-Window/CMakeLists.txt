cmake_minimum_required(VERSION 3.5)

set(target 01-Window)

add_executable(${target} main.cpp)

target_include_directories(${target} PRIVATE ${GLAD_INC_DIR})
target_link_libraries(${target} lib::glad)
add_dependencies(${target} lib::glad)

set_target_properties(${target} PROPERTIES
    LINK_DIRECTORIES ${LIB_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}/${target}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BIN_DIR}/${target}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BIN_DIR}/${target}
)




