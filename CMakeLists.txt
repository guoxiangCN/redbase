cmake_minimum_required(VERSION 3.23)

project(redbase
        VERSION 1.0.0
        DESCRIPTION "a simple implementation of dbms"
        LANGUAGES CXX)   

# Enable C++11
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/src/)
include_directories(${PROJECT_SOURCE_DIR}/deps/googletest/googletest/include/)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/rm)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/pf)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/bin)
add_subdirectory(${PROJECT_SOURCE_DIR}/deps/googletest)