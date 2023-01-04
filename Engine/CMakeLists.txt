cmake_minimum_required(VERSION 3.0)

find_package(OpenGL REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/Dependencies/glad/include
    ${CMAKE_SOURCE_DIR}/Dependencies/glfw/include
    ${CMAKE_SOURCE_DIR}/Dependencies/glm
    ${CMAKE_SOURCE_DIR}/Dependencies/assimp/include

    ${CMAKE_SOURCE_DIR}/Dependencies/imgui
    ${CMAKE_SOURCE_DIR}/Dependencies/
    ${OpenGL_INCLUDE_DIRS}
)
add_library( GEMGEMENGINE_LIB
    Engine.cpp
    Camera.cpp
)

target_link_libraries( GEMGEMENGINE_LIB
    GLAD_LIB
    ${OpenGL_LIBRARIES}
    glfw
    glm
    assimp
    IMGUI_LIB
)