cmake_minimum_required(VERSION 3.16)

project(DSLib VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(dslib
    src/Stack.cpp
    src/Queue.cpp
    src/LinkedList.cpp
    src/Tree.cpp
    src/Graph.cpp
    src/school/School.cpp
    src/hospital/Hospital.cpp
    src/bank/Bank.cpp
)

target_include_directories(dslib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(dslib_demo examples/main.cpp)
target_link_libraries(dslib_demo PRIVATE dslib)