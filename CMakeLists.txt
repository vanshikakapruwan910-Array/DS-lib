cmake_minimum_required(VERSION 3.16)

project(DSLib VERSION 1.0.0 LANGUAGES CXX)

option(DSLIB_BUILD_EXAMPLES "Build the example program" ON)
option(DSLIB_BUILD_TESTS "Build basic domain smoke tests" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Reusable core DSA library + School and Hospital domain modules.
# src/main.cpp is intentionally excluded because it contains an old,
# merge-conflicted demo main() and is not part of the library.
add_library(dslib
    src/array.cpp
    src/array2D.cpp
    src/graph.cpp
    src/linkedlist.cpp
    src/q1.cpp
    src/stack.cpp
    src/tree.cpp
    school/school.cpp
    hospital/hospital1.cpp
)

add_library(DSLib::dslib ALIAS dslib)

# Headers are grouped by module but exposed through one public include root.
target_include_directories(dslib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/dslib>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/school>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/hospital>
        $<INSTALL_INTERFACE:include/dslib>
        $<INSTALL_INTERFACE:include/school>
        $<INSTALL_INTERFACE:include/hospital>
)

if(MSVC)
    target_compile_options(dslib PRIVATE /W4)
else()
    target_compile_options(dslib PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(DSLIB_BUILD_EXAMPLES)
    add_executable(dslib_demo examples/main.cpp)
    target_link_libraries(dslib_demo PRIVATE DSLib::dslib)
endif()

include(CTest)
if(BUILD_TESTING AND DSLIB_BUILD_TESTS)
    add_executable(domain_smoke_test tests/domain_smoke_test.cpp)
    target_link_libraries(domain_smoke_test PRIVATE DSLib::dslib)
    add_test(NAME domain_smoke_test COMMAND domain_smoke_test)
endif()

include(GNUInstallDirs)
install(TARGETS dslib
    EXPORT DSLibTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include/dslib/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dslib)
install(DIRECTORY include/school/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/school)
install(DIRECTORY include/hospital/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/hospital)
install(EXPORT DSLibTargets
    FILE DSLibTargets.cmake
    NAMESPACE DSLib::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DSLib
)

# Python bindings using pybind11
option(DSLIB_BUILD_PYTHON "Build Python bindings" ON)

if(DSLIB_BUILD_PYTHON)
    find_package(Python COMPONENTS Interpreter Development.Module REQUIRED)
    find_package(pybind11 CONFIG REQUIRED)

    pybind11_add_module(dslib_python bindings/bindings.cpp)

    set_target_properties(dslib_python PROPERTIES
        OUTPUT_NAME dslib
        ARCHIVE_OUTPUT_NAME dslib_python
    )

    target_link_libraries(dslib_python PRIVATE DSLib::dslib)
endif()