#include <QApplication>
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
