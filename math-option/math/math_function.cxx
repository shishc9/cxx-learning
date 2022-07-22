#include "math_function.h"

int math_pow(int base, int exponent) {
    if (base <= 0 || exponent <= 0) {
        return -1;
    }

    int result = base;

    for (int i = 1; i < exponent; i++) {
        result = result * base;
    }

    return result;
}