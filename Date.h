//
// Created by riccardo on 11/11/20.
//

#ifndef PROJECT_DATE_H
#define PROJECT_DATE_H

#include "string"

using namespace std;

class Date {

public:
    Date(int day, int month, int year, int dayOfWeek, bool leapYear, string format = "Extended Format");

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    void setDayOfWeek(int dayOfWeek);

    void setLeapWeek(bool isLeapWeek);

    void setFormat(const string &format);

    string getFullString() const;

    int getDay();

    int getMonth();

    int getYear();

    int getDayOfWeek() const;

    bool isLeapYear();

    string &getFormat();

    bool checkIfIsALeapYear(int year);

private:
    int day, month, year, dayOfWeek;
    string format;
    bool leapYear;

};


#endif //PROJECT_DATE_H
