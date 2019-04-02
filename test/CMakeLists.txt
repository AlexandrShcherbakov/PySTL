cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

project(Test)

include(CTest)
enable_testing()

include(DownloadProject)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

add_executable(runUnitTests gtest.cpp ${test_SRCS}
        test_enumerate.cpp
        test_len.cpp
        test_print.cpp
        test_range.cpp
        test_zip.cpp
        test_sum.cpp
        test_all.cpp
        test_any.cpp)
target_link_libraries(runUnitTests gtest gmock)