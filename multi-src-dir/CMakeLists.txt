cmake_minimum_required(VERSION 3.23.0)
project(CMAKE_MULTI_SRC_DIR)

# 找到当前目录下所有源文件 并将名称保存到SRC_DIR变量
aux_source_directory(. SRC_DIR)

# 添加 math 子目录
add_subdirectory(math)

add_executable(multi_src_dir ${SRC_DIR})

# 添加链接库
target_link_libraries(multi_src_dir math_functions)
