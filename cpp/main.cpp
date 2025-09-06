#include "header.h"
#include <boost/container/small_vector.hpp>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // 输出 UTF-8 编码
#endif
    std::cout.setf(std::ios_base::boolalpha);
    auto benchmark = [](std::string_view name, auto&& func) {
        auto start = std::chrono::high_resolution_clock::now();
        func();
        auto end = std::chrono::high_resolution_clock::now();
        std::println("{} took {}ms", name, std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
        };
    return 0;
}
