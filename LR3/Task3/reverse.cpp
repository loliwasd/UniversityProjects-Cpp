#include "reverse.h"
#include <cmath>

Reverse::Reverse() {}

int Reverse::countDigits(int n) {
    if (n < 10) return 1;
    return 1 + countDigits(n / 10);
}

int Reverse::reverseNumber(int n, int digits) {
    if (n < 10)
        return n;
    return (n % 10) * static_cast<int>(pow(10, digits - 1)) + reverseNumber(n / 10, digits - 1);
}
