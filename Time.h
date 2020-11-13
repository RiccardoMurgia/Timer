//
// Created by riccardo on 11/11/20.
//

#ifndef PROJECT_TIME_H
#define PROJECT_TIME_H

#include "string"

using namespace std;

class Time {

public:

    Time(int hours, int minutes, int seconds);

    void setHours(int hours);

    void setMinutes(int minutes);

    void setSeconds(int seconds);

    void setFormat(const string &format);

    int getHours() const;

    int getMinutes() const;

    int getSeconds() const;

    string &getFormat();

    string getFullString() const;


private:
    int hours, minutes, seconds;
    string format;
};


#endif //PROJECT_TIME_H
