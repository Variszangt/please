cmake_minimum_required(VERSION 3.18.0)
set(TARGET_NAME "please")
project(${TARGET_NAME})

add_executable(${TARGET_NAME}
    src/main.cpp
)

# Local include folder:
target_include_directories(${TARGET_NAME} PRIVATE src/)

# Use C++20:
target_compile_features(${TARGET_NAME} PRIVATE cxx_std_20)

# Enforce warnings:
if(MSVC)
  target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
endif()

# /*------------------------------------------------------------------*/
# External dependencies:

# doctest
find_package(doctest CONFIG REQUIRED)
target_link_libraries(${TARGET_NAME} PRIVATE doctest::doctest)

# spdlog
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${TARGET_NAME} PRIVATE spdlog::spdlog)

# fmt
find_package(fmt CONFIG REQUIRED)
target_link_libraries(${TARGET_NAME} PRIVATE fmt::fmt)
