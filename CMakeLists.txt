cmake_minimum_required(VERSION 3.25)

project(cpw
    VERSION 0.1.0
    DESCRIPTION "Coplanar Waveguide numerical simulator"
    LANGUAGES CXX
)

# ------------------------------------------------------------
# C++ standard
# ------------------------------------------------------------

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------------------------------
# Options
# ------------------------------------------------------------

option(CPW_BUILD_CLI "Build command-line application" ON)
option(CPW_BUILD_TESTS "Build tests" ON)

# ------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------

find_package(Eigen3 CONFIG REQUIRED)

# ------------------------------------------------------------
# CPW library
# ------------------------------------------------------------

# add_library(cpw
#     src/cpw.cpp
#     src/geometry.cpp
#     src/material.cpp
#
#     src/math/cpw_math.cpp
#     src/math/elliptic.cpp
# )

add_library(cpw
    src/cpw.cpp
    src/geometry.cpp
    src/material.cpp
)

target_include_directories(cpw
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(cpw
    PUBLIC
        Eigen3::Eigen
)

target_compile_features(cpw
    PUBLIC
        cxx_std_20
)

# ------------------------------------------------------------
# Compiler warnings
# ------------------------------------------------------------

if(MSVC)
  target_compile_options(cpw PRIVATE
        /W4
        /permissive-
  )
else()
  target_compile_options(cpw PRIVATE
        -Wall
        -Wextra
        -Wpedantic
  )
endif()

# ------------------------------------------------------------
# CLI
# ------------------------------------------------------------

if(CPW_BUILD_CLI)

  add_executable(cpw-cli
        apps/cli/main.cpp
  )

  target_link_libraries(cpw-cli
        PRIVATE
            cpw
  )

endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ------------------------------------------------------------
# Tests
# ------------------------------------------------------------

# if(CPW_BUILD_TESTS)
#
#   enable_testing()
#
#   find_package(GTest CONFIG REQUIRED)
#
#   add_executable(cpw-tests
#         tests/test_cpw.cpp
#     )
#
#   target_link_libraries(cpw-tests
#         PRIVATE
#             cpw
#             GTest::gtest_main
#     )
#
#   include(GoogleTest)
#
#   gtest_discover_tests(cpw-tests)
#
# endif()
