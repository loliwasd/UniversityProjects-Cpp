#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Boots {
    int size;
    float sm_size;
    bool isWaterproof;
    char gender;
    char brand[10];

    void serialize(QDataStream &stream) const {
        stream << size << sm_size << isWaterproof << gender;
        stream.writeRawData(brand, 10);
    }

    void deserialize(QDataStream &stream) {
        stream >> size >> sm_size >> isWaterproof >> gender;
        stream.readRawData(brand, 10);
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadBtn_clicked();

    void on_saveFileBtn_clicked();

    void on_addTextBtn_clicked();

    void on_readTextBtn_clicked();

    void on_addBinaryBtn_clicked();

    void on_readBinaryBtn_clicked();

private:

    Ui::MainWindow *ui;
    const QString textFileName = "MurashkoLab20_1.txt";
    const QString binaryFileName = "MurashkoLab20_2.bin";

    void loadFromFile(const QString& path);
    Boots getBootsFromInput();
    void displayBoots(const Boots &boots);
};
#endif // MAINWINDOW_H
