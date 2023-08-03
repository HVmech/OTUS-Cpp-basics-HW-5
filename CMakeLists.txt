cmake_minimum_required(VERSION 3.5)

project(stat CXX)

add_executable(stat
    pct.cpp
    main.cpp
)

target_include_directories(stat PRIVATE include)

target_compile_features(stat PUBLIC cxx_std_17)