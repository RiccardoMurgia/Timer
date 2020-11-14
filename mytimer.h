#ifndef MYTIMER_H
#define MYTIMER_H

#include <QWidget>
#include "Counter.h"

namespace Ui {
    class MyTimer;
}

class MyTimer : public QWidget, public Observer {
Q_OBJECT

public:

    explicit MyTimer(QWidget *parent = nullptr);

    ~MyTimer();

    void update() override;

public slots:

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_restButton_clicked();

private:
    Ui::MyTimer *ui;
    Counter *counter;
    Time *time;


};

#endif // MYTIMER_H
