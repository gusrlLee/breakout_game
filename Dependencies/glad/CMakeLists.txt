cmake_minimum_required(VERSION 3.0)
add_library(GLAD_LIB src/glad.c)

find_package(OpenGL REQUIRED)

target_include_directories(GLAD_LIB PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${OpenGL_INCLUDE_DIRS}
)

target_link_libraries(GLAD_LIB 
    ${OpenGL_LIBRARIES}
)
