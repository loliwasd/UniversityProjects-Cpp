#include "tobinary.h"

ToBinary::ToBinary() {
    out = "";
}

void ToBinary::decimalToBinary(int n) {
    if (n == 0 && out.isEmpty()) {
        out = "0";
        return;
    }
    if (n == 0) return;
    decimalToBinary(n / 2);
    out += QString::number(n % 2);
}
