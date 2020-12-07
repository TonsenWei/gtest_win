cmake_minimum_required(VERSION 3.0)  # cmake -G "MinGW Makefiles" ..
project(GTESTWIN_TEST)

# gtest库相关
# 如果把gtest放到test目录下，则使用如下包含关系：
add_subdirectory(./googletest-release-1.8.1)  # 编译gtest
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/googletest-release-1.8.1/googletest/include)  # 包含gtest等头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/googletest-release-1.8.1/googlemock/include)  # 包含gtest等头文件


# 头文件目录
include_directories("../src/include")
# 源文件目录
AUX_SOURCE_DIRECTORY("../src/src" SRCS)

# 测试代码目录
AUX_SOURCE_DIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}" TEST_SRCS)

# 生成可执行程序
add_executable(gtest_win_test ${DIR_SRCS} ${TEST_SRCS})

# 链接测试库,pthread 库一定要写在 ${GTEST_BOTH_LIBRARIES} 的后面, 否则编译时会报错,
# GTEST_BOTH_LIBRARIES表示链接google test的两个库
target_link_libraries( gtest_win_test
        PRIVATE 
        gtest
        gtest_main  # 使用gtest带的main函数,如果检测到外部有main函数，则使用外部main函数,外部main函数要配置gtest初始化。
        gmock
        gmock_main  # 使用gmock带的main函数,如果检测到外部有main函数，则使用外部main函数,与gtest_main同时存在则自动配置。
        pthread )
