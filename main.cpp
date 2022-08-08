#include "plasma_beautifier_qt.h"
#include "./ui_plasma_beautifier_qt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    plasma_beautifier_qt w;
    w.setFixedSize(800,700);
    w.setWindowTitle("KDE Plasma 美化工具");
    w.setWindowOpacity(0.9);
    w.show();
    return a.exec();
}
