#include "ackermann.h"

Ackermann::Ackermann() {}

unsigned int Ackermann::ackermannFunc(unsigned int m, unsigned int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ackermannFunc(m - 1, 1);
    } else {
        return ackermannFunc(m - 1, ackermannFunc(m, n - 1));
    }
}
