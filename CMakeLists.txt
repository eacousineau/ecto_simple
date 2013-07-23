cmake_minimum_required(VERSION 2.8)

project(ecto_test)

#defines include directories, libraries a few macros
#that simplify creating ecto module targets.
find_package(ecto REQUIRED)

list(APPEND CMAKE_CXX_FLAGS "-std=c++0x")

#make all libraries appear in the build/lib directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

ectomodule(ecto_test DESTINATION ${CMAKE_BINARY_DIR} INSTALL
    src/cell.cpp
)