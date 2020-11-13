#include <iostream>
#include <QApplication>
#include <QDebug>
#include <QtWidgets/QLabel>
#include "Counter.h"
#include "mainwindow.h"

using namespace std;
Counter *Counter::instance = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
