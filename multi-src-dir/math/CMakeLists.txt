# 当前目录所有源文件编译进MUL_SRC_DIR_LIB变量
aux_source_directory(. MUL_SRC_DIR_LIB)

# 生成链接库
add_library(math_functions ${MUL_SRC_DIR_LIB})