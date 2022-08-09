#include "plasma_beautifier_qt.h"
#include "./ui_plasma_beautifier_qt.h"
#include <QTextStream>
#include <QFile>
#include <iostream>
#include <fstream>
plasma_beautifier_qt::plasma_beautifier_qt(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::plasma_beautifier_qt)
{
    ui->setupUi(this);
}

plasma_beautifier_qt::~plasma_beautifier_qt()
{
    delete ui;
}

void plasma_beautifier_qt::on_pushButton_clicked()
{
    system("plasmashell --version > /tmp/plasmashellversion");
    std::ifstream plasmashellversion("/tmp/plasmashellversion");
    std::ofstream plasmaversion("/tmp/plasmaversion");
    for(int i=1;!plasmashellversion.eof();i++)
    {
        char c;
        plasmashellversion>>c;
        if(plasmashellversion.eof()) break;
        if(i>=12) plasmaversion<<c;
    }
    plasmashellversion.close();
    plasmaversion.close();
    QFile inputFile("/tmp/plasmaversion");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();
    ui->plasmaversion->setText(line);
}




void plasma_beautifier_qt::on_pushButton_2_clicked()
{
    system("konsole -e /usr/lib/plasma-beautifier-qt/data/installlightly.sh");
}


void plasma_beautifier_qt::on_pushButton_3_clicked()
{
    system("cp -r /usr/lib/plasma-beautifier-qt/data/lightlyrc ~/.config/");
}


void plasma_beautifier_qt::on_pushButton_4_clicked()
{
    system("systemsettings5 kcm_style");
}


void plasma_beautifier_qt::on_pushButton_5_clicked()
{
    system("tar -xvf /usr/lib/plasma-beautifier-qt/data/desktoptheme-DeepinV20-dark.tar.xz -C ~/");
}


void plasma_beautifier_qt::on_pushButton_6_clicked()
{
    system("systemsettings5 kcm_desktoptheme");
}


void plasma_beautifier_qt::on_pushButton_7_clicked()
{
    system("konsole -e /usr/lib/plasma-beautifier-qt/data/installlightly.sh");
}


void plasma_beautifier_qt::on_pushButton_8_clicked()
{
    system("konsole -e /usr/lib/plasma-beautifier-qt/data/installklassy.sh");
}


void plasma_beautifier_qt::on_pushButton_9_clicked()
{
    system("cp -r /usr/lib/plasma-beautifier-qt/data/klassyrc ~/.config/");
}


void plasma_beautifier_qt::on_pushButton_10_clicked()
{
    system("systemsettings5 kcm_kwindecoration");
}


void plasma_beautifier_qt::on_pushButton_11_clicked()
{
    system("mkdir -p ~/.local/share/color-schemes&&cp -r /usr/lib/plasma-beautifier-qt/data/Lightly-transparent.colors ~/.local/share/color-schemes/");
}


void plasma_beautifier_qt::on_pushButton_12_clicked()
{
    system("systemsettings5 kcm_colors");
}

