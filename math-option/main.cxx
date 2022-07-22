#include <iostream>
#include "config.h"

#ifdef USE_MATH
    #include "math/math_function.h"
#else
    #include <cmath>
#endif

int main() {

    #ifdef USE_MATH
        std::cout << "math_pow: " << math_pow(3, 3) << std::endl;
    #else
        std::cout << "cmath pow: " << pow(3, 3) << std::endl;
    #endif

    return 0;
}