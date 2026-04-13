#ifndef HANOI_H
#define HANOI_H

#include <QString>
#include <QTextEdit>

class Hanoi {
public:
    Hanoi(QTextEdit* outputBox);
    void solve(int n, const QString& from, const QString& to, const QString& aux);

private:
    QTextEdit* output;
    void move(int n, const QString& from, const QString& to, const QString& aux);
};

#endif // HANOI_H
