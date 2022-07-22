cmake_minimum_required(VERSION 3.23.0)

project(CMAKE_MULTI_SRC)

aux_source_directory(. SRC_DIR)

# 下面两种写法均可.
add_executable(multi_exe ${SRC_DIR})
# add_executable(multi_exe main.cxx math_function.cxx)