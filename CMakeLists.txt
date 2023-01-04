cmake_minimum_required(VERSION 3.0)
project(gemgemEngine) 
SET(CMAKE_CXX_STANDARD 11)
# libraries
add_subdirectory( Dependencies )

# Engine
add_subdirectory( Engine )

# application
add_subdirectory( App )
