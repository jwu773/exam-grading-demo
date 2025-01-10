#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

// TODO: 实现正确的缓存优化斐波那契计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    int d = cache.cached;
    for (; d <= i; ++d) {
        cache.cache[d] = cache.cache[d - 1] + cache.cache[d - 2];
    }
    cache.cached = d;
    return cache.cache[i];
}

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>
    FibonacciCache fib;
    unsigned long long arr[16];
    arr[0] = 0;
    arr[1] = 1;
    //fib.cache = arr;   error
    //memcpy(fib.cache, arr, sizeof(arr));
    for(int i =0; i < 16; i++)
        fib.cache[i] = arr[i];
    fib.cached = 2;
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
