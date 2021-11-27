cmake_minimum_required (VERSION 3.9)

project(thread_example)


set(SRCS threads/plane.hpp threads/airport.hpp source.cpp)

add_executable (thread_example ${SRCS})

find_package (Threads)

target_compile_features(thread_example PUBLIC cxx_std_17)
target_link_libraries (thread_example Threads::Threads)