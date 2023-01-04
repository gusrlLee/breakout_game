cmake_minimum_required(VERSION 3.0)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(
    ${CMAKE_SOURCE_DIR}/Engine
    ${CMAKE_SOURCE_DIR}/Dependencies
)

target_link_libraries(${PROJECT_NAME} 
    GEMGEMENGINE_LIB
    GLAD_LIB
    ${OpenGL_LIBRARIES}
    glfw
    glm
    assimp
)