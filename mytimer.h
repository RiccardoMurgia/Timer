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

    void on_setTimerButton_clicked();

    void on_startButton_clicked();

    void on_pauseButton_clicked();

    void on_resetButton_clicked();

private:
    Ui::MyTimer *ui;
    Counter *counter;
    Time *time;
    bool start, pause, setFlag;


};

#endif // MYTIMER_H
