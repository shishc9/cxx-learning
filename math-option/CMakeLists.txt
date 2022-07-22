cmake_minimum_required(VERSION 3.23.0)
project(MATH_OPTION)

# 添加一个配置头文件，用于处理cmake对源码的设置
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

# 是否使用自己的math库
option(USE_MATH
    "use provided math impl" ON
)

# 是否加入自己math库
if(USE_MATH)
    include_directories("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math)
    set(EXTRA_LIBS ${EXTRA_LIBS} math_functions)
endif(USE_MATH)

aux_source_directory(. SRC)

add_executable(option_exe ${SRC})
target_link_libraries(option_exe ${EXTRA_LIBS})