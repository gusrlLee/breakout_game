cmake_minimum_required(VERSION 3.0)

find_package(OpenGL REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/Dependencies/glad/include
    ${CMAKE_SOURCE_DIR}/Dependencies/glfw/include
    ${CMAKE_SOURCE_DIR}/Dependencies/glm
    ${OpenGL_INCLUDE_DIRS}
)
add_executable(${PROJECT_NAME} 
    main.cpp
    Engine.cpp
)

target_link_libraries(${PROJECT_NAME} 
    GLAD_LIB
    ${OpenGL_LIBRARIES}
    glfw
    glm
)