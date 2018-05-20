cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

project(Test)

project(Example)

include(CTest)
enable_testing()

#set(gtest_disable_pthreads on) #needed in MinGW
if (UNIX)
    include(~/3rdPartyLibs/DownloadProject/DownloadProject.cmake)
else(UNIX)
    include(D:\\Projects\\DownloadProject\\DownloadProject.cmake)
endif(UNIX)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

#set(test_SRCS ADD ALL TEST SOURCE FILES HERE)
add_executable(runUnitTests gtest.cpp ${test_SRCS} test_enumerate.cpp test_len.cpp test_range.cpp test_zip.cpp)
target_link_libraries(runUnitTests gtest gmock)