cmake_minimum_required(VERSION 3.0)
project(dronaSrcLibSTLLib)

# Search .cpp in ./src
file(GLOB_RECURSE sources Src/*.cpp)
file(GLOB_RECURSE includes Includes/*.h)

# Include path
INCLUDE_DIRECTORIES(includes)

# Build exectuable
add_library(STLLib STATIC ${sources} ${includes})

