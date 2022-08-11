#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class plasma_beautifier_qt; }
QT_END_NAMESPACE

class plasma_beautifier_qt : public QMainWindow
{
    Q_OBJECT

public:
    plasma_beautifier_qt(QWidget *parent = nullptr);
    ~plasma_beautifier_qt();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    void loadkwinversionTextFile();
    Ui::plasma_beautifier_qt *ui;
};
