# CMakeList.txt: cpp-new-feature 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
set(Boost_INCLUDE_DIRS "E:/Development/boost_1_87_0/build/include")
set(Boost_LIBRARIES "E:/Development/boost_1_87_0/build/lib")

# 将源代码添加到此项目的可执行文件。
add_executable (cpp_main "main.cpp" )

# TODO: 如有需要，请添加测试并安装目标。
# 包含当前目录的头文件
target_include_directories(cpp_main PRIVATE .)

# 包含Boost头文件
target_include_directories(cpp_main PRIVATE ${Boost_INCLUDE_DIRS})

# 链接Boost库
target_link_libraries(cpp_main PRIVATE ${Boost_LIBRARIES})

# 添加MSVC特定的编译和链接选项
if (MSVC)
    # 为Release配置设置优化和调试信息
    target_compile_options(cpp_main PRIVATE
        "$<$<CONFIG:Release>:/O2 /Zi>"
    )
    
    # 确保Release配置生成PDB文件
    target_link_options(cpp_main PRIVATE
        "$<$<CONFIG:Release>:/DEBUG /OPT:REF /OPT:ICF>"
    )

    # 设置栈大小为4MB (4194304字节)
    target_link_options(cpp_main PRIVATE
        "/STACK:4194304"
    )
else()
    # GCC/Clang 使用 -Wl,--stack 选项
    target_link_options(cpp_main PRIVATE
        "-Wl,--stack,4194304"
    )
endif()

# char / signed char / unsigned char 都是独立类型，可以使用以下方式指定编译器char是signed char还是unsigned char
# -funsigned-char
# -fsigned-char
#find_package(OpenMP REQUIRED)
#target_link_libraries(cpp_main OpenMP::OpenMP_CXX) # 添加OpenMP库
