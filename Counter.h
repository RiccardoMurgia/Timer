//
// Created by riccardo on 11/11/20.
//

#ifndef PROJECT_COUNTER_H
#define PROJECT_COUNTER_H


#include "Time.h"
#include "Date.h"
#include "Observer.h"
#include<ctime>
#include<cstdlib>
#include <QtCore/QObject>
#include <QtCore/QTimer>


class Counter : public QObject {
Q_OBJECT


public:


    string &getTimeFormat();

    string &getDateFormat();

    void setTimeFormat(const string &basicString);

    void setDateFormat(const string &format);

    string getStringDate();

    string getStringTime();

    static Counter *getInstance();

    virtual ~Counter();

    void attach(Observer *o);

    void detach(Observer *o);

    void notify();

public slots:

    void increase();

private:
    list<Observer *> obsList;
    static Counter *instance;
    QTimer *qTimer;
    Time *currentTime;
    Date *currentDate;
    bool active;

    Counter();

    bool isNotLastDayOfTheMonth();


};


#endif //PROJECT_COUNTER_H
