#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "iostream"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include <mytimer.h>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>

#include "Counter.h"
#include "Time.h"
#include "Date.h"


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

    void on_openTimer_clicked();

    void on_selectTimeFormat_currentTextChanged(const QString &arg1);

    void on_selectDateFormat_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    MyTimer *myTimer;
    Counter *counter;


};

#endif // MAINWINDOW_H
