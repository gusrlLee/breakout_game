cmake_minimum_required(VERSION 3.0)

# set GLFW 
set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")

# add_subdirectory(assimp)
add_subdirectory(glad)
add_subdirectory(glfw)
add_subdirectory(glm)
# add_subdirectory(imgui)

