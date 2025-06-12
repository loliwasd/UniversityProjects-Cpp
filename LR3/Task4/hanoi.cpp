#include "hanoi.h"

Hanoi::Hanoi(QTextEdit* outputBox) : output(outputBox) {}

void Hanoi::solve(int n, const QString& from, const QString& to, const QString& aux) {
    output->clear();
    move(n, from, to, aux);
}

void Hanoi::move(int n, const QString& from, const QString& to, const QString& aux) {
    if (n == 1) {
        output->append(QString("Move disk 1 from %1 to %2").arg(from, to));
        return;
    }
    move(n - 1, from, aux, to);
    output->append(QString("Move disk %1 from %2 to %3").arg(n).arg(from, to));
    move(n - 1, aux, to, from);
}
