//
// Created by riccardo on 11/11/20.
//

#ifndef PROJECT_COUNTER_H
#define PROJECT_COUNTER_H


#include "Time.h"
#include "Date.h"
#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include<cstdlib>
#include <QtCore/QObject>
#include <QtCore/QTime>
#include <QtCore/QTimer>


class Counter : public QObject, public Subject {
Q_OBJECT

public:

    void setTimeFormat(const TimeFormats &format);

    void setDateFormat(const DataFormat &format);

    const int getSeconds() const;

    const int getMinutes() const;

    const int getHours() const;

    const string getStringDate() const;

    const string getStringTime() const;

    static Counter *getInstance();

    virtual ~Counter();

    void attach(Observer *o) override;

    void detach(Observer *o) override;

    void notify() override;

public slots:

    void increase();

private:
    list<Observer *> obsList;
    static Counter *instance;
    QTimer *qTimer;
    Time *currentTime;
    Date *currentDate;

    Counter();

    bool isNotLastDayOfTheMonth();


};


#endif //PROJECT_COUNTER_H
