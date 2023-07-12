#cmake 最低版本和项目名
cmake_minimum_required(VERSION 3.0)
project(rpc)

#设置项目可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#设置项目库文件输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#设置项目编译的头文件搜索路径  -I
include_directories(${PROJECT_SOURCE_DIR}/src/include)  #src里面是框架的代码
include_directories(${PROJECT_SOURCE_DIR}/example)  #example是业务的代码
#设置项目库文件搜索路径 -L
link_directories(${PROJECT_SOURCE_DIR}/lib)

#生成debug版本，就能调试了
set(CMAKE_BUILD_TYPE "Debug")

add_subdirectory(src)#框架代码
add_subdirectory(example)#使用框架的 业务示例代码