cmake_minimum_required(VERSION 3.10)
project(ramcpp)

option(RAMCPP_TESTS "Enable Tests" OFF)
option(RAMCPP_EXAMPLES "Enable Examples" OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build Type" FORCE)
endif()

add_library(${PROJECT_NAME} "")

set_target_properties(${PROJECT_NAME} PROPERTIES
    LINKER_LANGUAGE          CXX
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

target_sources(${PROJECT_NAME} PRIVATE
    include/ramcpp/defaults.hpp
    include/ramcpp/hash.hpp
    include/ramcpp/ram.hpp
    include/ramcpp/types.hpp

    src/ram.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

if (RAMCPP_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

if (RAMCPP_EXAMPLES)
    add_subdirectory(example)
endif()
