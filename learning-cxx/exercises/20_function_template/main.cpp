﻿#include "../exercise.h"

// READ: 函数模板 <https://zh.cppreference.com/w/cpp/language/function_template>
// TODO: 将这个函数模板化
template<typename T>
T plus(T a, T b){
	return a + b;
}


int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");
    //std::cout << plus(1u,2u) << "... " << (plus(1.1, 2.2) - 3.3) << "... " << (plus(0.25, 0.125) - 0.375) << std::endl;
    // THINK: 浮点数何时可以判断 ==？何时必须判断差值？
    ASSERT(plus(1.25f, 2.5f) == 3.75f, "Plus two float");
    ASSERT(plus(1.25, 2.5) == 3.75, "Plus two double");
    // TODO: 修改判断条件使测试通过
    ASSERT(plus(0.1, 0.2) - 0.3 < 1e-5, "How to make this pass?");

    return 0;
}