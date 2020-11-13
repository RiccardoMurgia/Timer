#ifndef MYTIMER_H
#define MYTIMER_H

#include <QWidget>
#include "Counter.h"

namespace Ui {
    class MyTimer;
}

class MyTimer : public QWidget {
Q_OBJECT

public:

    explicit MyTimer( QWidget *parent = nullptr);

    ~MyTimer();

private:
    Ui::MyTimer *ui;
    Counter* counter;
};

#endif // MYTIMER_H
