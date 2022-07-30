# cxx learning repo

single-src 单个源文件编译
```bash
cd single-src
cmake .
make
```

multi-src 多源文件单目录编译
```bash
cd multi-src
cmake .
make
```

multi-src-dir 多源文件多目录编译 (cmake注释在这里！)

根目录与math目录都需要CMakeLists.txt，将math目录编译成静态库再由main函数调用
```bash
cd multi-src-dir
cmake .
make
```

math-option 多源文件多目录选择性编译
```bash
cd math-option
cmake .
make
```

thread 线程包
```
# thread.cxx
g++ thread.cxx -lpthread
```