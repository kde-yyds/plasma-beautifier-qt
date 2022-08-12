#include "plasma_beautifier_qt.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    plasma_beautifier_qt w;
    w.setFixedSize(1280,720);
    w.setWindowTitle("KDE Plasma 美化工具");
    w.setWindowFlags(Qt::CustomizeWindowHint |
                     Qt::WindowMinimizeButtonHint |
                     Qt::WindowMaximizeButtonHint);
    w.setWindowOpacity(0.9);
    w.show();
    return a.exec();
}

