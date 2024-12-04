cmake_minimum_required(VERSION 3.12)

project(inf5171-243-tp4 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(MPI REQUIRED)

add_library(core
  dvec.cpp
  dvec.h
)
target_link_libraries(core PUBLIC MPI::MPI_C MPI::MPI_CXX)

add_executable(bench_bcast bench_bcast.cpp)
target_link_libraries(bench_bcast PRIVATE core)

add_executable(test_core test_core.cpp)
target_link_libraries(test_core PRIVATE core)

