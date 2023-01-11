cmake_minimum_required(VERSION 3.10)
project(template)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

option(TEMPLATE_TESTS "Enable Tests" OFF)
option(TEMPLATE_EXAMPLES "Enable Examples" OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build Type" FORCE)
endif()

add_library(${PROJECT_NAME} "")

set_target_properties(${PROJECT_NAME} PROPERTIES
    LINKER_LANGUAGE          CXX
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

target_sources(${PROJECT_NAME} PRIVATE
    include/template/template.hpp

    src/template.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Threads::Threads
)

if (TEMPLATE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

if (TEMPLATE_EXAMPLES)
    add_subdirectory(example)
endif()
