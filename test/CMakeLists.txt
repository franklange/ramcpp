project(ramcpp_test)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(${PROJECT_NAME} "")

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/tests"
)
target_sources(${PROJECT_NAME} PRIVATE
    ram_TEST.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ramcpp
    GTest::gmock_main
)

gtest_discover_tests(${PROJECT_NAME})
