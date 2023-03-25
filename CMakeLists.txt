cmake_minimum_required(VERSION 3.21)
project(monstersprite)

set(CMAKE_CXX_STANDARD 14)

add_executable(monstersprite src/main.cpp)
add_subdirectory(src include)

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
message(STATUS ">>>>>>>>>>>>>>>" ${SFML_INCLUDE_DIRS} " and found? " ${SFML_FOUND})

target_link_libraries(monstersprite comps sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

