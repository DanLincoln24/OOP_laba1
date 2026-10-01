cmake_minimum_required(VERSION 3.14.0)
project(laba1 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(business_logic src/dynamic_array.cpp src/bubble_sort.cpp)
add_executable(laba1 src/main.cpp)
target_link_libraries(laba1 business_logic)

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests src/test_bubble_sort.cpp src/test_dynamic_array.cpp)

target_link_libraries(unit_tests GTest::gtest_main business_logic)

include(GoogleTest)
gtest_discover_tests(unit_tests)