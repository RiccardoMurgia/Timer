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

    explicit MyTimer( QWidget *parent = nullptr);

    ~MyTimer();

    void update() override;


private:
    Ui::MyTimer *ui;
    Counter* counter;

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_pushButton_3_clicked();
};

#endif // MYTIMER_H
