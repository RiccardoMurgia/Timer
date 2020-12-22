//
// Created by riccardo on 11/11/20.
//

#ifndef PROJECT_TIME_H
#define PROJECT_TIME_H

#include <stdexcept>
#include "string"

using namespace std;
enum TimeFormats{Format12h, Format24h};


class Time {

public:

    Time(int hours, int minutes, int seconds, TimeFormats format =  Format12h);

    void setHours(int hours);

    void setMinutes(int minutes);

    void setSeconds(int seconds);

    void setFormat(const TimeFormats &format);

    int getHours() const;

    int getMinutes() const;

    int getSeconds() const;

    string getFullString() const;

    TimeFormats &getFormat();

private:
    int hours, minutes, seconds;
    TimeFormats format;



};


#endif //PROJECT_TIME_H
