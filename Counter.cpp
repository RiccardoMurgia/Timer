//
// Created by riccardo on 11/11/20.
//

#include <QtCore/QTime>
#include "Counter.h"

Counter::Counter() {
    QDateTime currentDateTime = QDateTime::currentDateTime();
    currentTime = new Time(currentDateTime.time().hour(), currentDateTime.time().minute(),
                           currentDateTime.time().second());
    currentDate = new Date(currentDateTime.date().day(), currentDateTime.date().month(), currentDateTime.date().year(),
                           currentDateTime.date().dayOfWeek(),
                           currentDateTime.date().isLeapYear(currentDateTime.date().year()));
    qTimer = new QTimer(this);
    connect(qTimer, SIGNAL(timeout()), this, SLOT(increase()));
    qTimer->start(1000);
    increase();
}

Counter::~Counter() {
    delete currentDate;
    delete currentTime;
    for (Observer *o:obsList)
        obsList.remove(o);
}

Counter *Counter::getInstance() {
    if (instance == nullptr)
        instance = new Counter();
    return instance;
}

string Counter::getStringTime() {
    return currentTime->getFullString();
}

string Counter::getStringDate() {
    return currentDate->getFullString();
}

string &Counter::getTimeFormat() {
    return currentTime->getFormat();
}

string &Counter::getDateFormat() {
    return currentDate->getFormat();
}

void Counter::setTimeFormat(const string& format) {
    currentTime->setFormat(format);
}

void Counter::setDateFormat(const string& format) {
    currentTime->setFormat(format);
}

void Counter::attach(Observer *o) {
    obsList.push_back(o);
}

void Counter::detach(Observer *o) {
    obsList.remove(o);
}

void Counter::notify() {
    for (Observer *o :obsList)
        o->update();
}

void Counter::increase() {
    if (currentTime->getSeconds() < 59)
        currentTime->setSeconds(currentTime->getSeconds() + 1);
    else {
        currentTime->setSeconds(0);
        if (currentTime->getMinutes() < 59)
            currentTime->setMinutes(currentTime->getMinutes() + 1);
        else {
            currentTime->setMinutes(0);
            if (currentTime->getHours() < 23)
                currentTime->setHours(currentTime->getHours() + 1);
            else {
                currentTime->setHours(0);
                if (check()) {
                    currentDate->setDay(currentDate->getDay() + 1);
                } else {
                    currentDate->setDay(1);
                    if (currentDate->getMonth() < 12)
                        currentDate->setMonth(currentDate->getMonth() + 1);
                    else {
                        currentDate->setMonth(1);
                        currentDate->setYear(currentDate->getYear() + 1);

                    }
                }
            }

        }
    }
    notify();
}

bool Counter::check() {
    if ((currentDate->getDay() + 1 <= 30 && currentDate->getMonth() != 2) ||
        currentDate->getDay() + 1 <= 28 ||
        (currentDate->getDay() + 1 == 29 && currentDate->isLeapYear() == true) ||
        (currentDate->getDay() + 1 == 31 &&
         (currentDate->getMonth() != 4 && currentDate->getMonth() != 6 && currentDate->getMonth() != 9 &&
          currentDate->getMonth() != 11 && currentDate->getMonth() != 2))) {
        return true;
    } else {
        return false;
    }
}








