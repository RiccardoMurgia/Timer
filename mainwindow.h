#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mytimer.h>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include "Counter.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Observer {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void update() override;

private slots:

    void on_pushButton_clicked();

    void changeTimeFormat();

    void changeDateFormat();

private:
    Ui::MainWindow *ui;
    MyTimer *myTimer;
    Counter *counter;
};

#endif // MAINWINDOW_H
