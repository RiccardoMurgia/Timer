//
// Created by riccardo on 11/11/20.
//

#include "Time.h"

Time::Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds),
                                                  format("12h Form") {}

void Time::setHours(int hours) {
    Time::hours = hours;
}

void Time::setMinutes(int minutes) {
    Time::minutes = minutes;
}

void Time::setSeconds(int seconds) {
    Time::seconds = seconds;
}

void Time::setFormat(const string &format) {
    Time::format = format;
}

int Time::getHours() const {
    return hours;
}

int Time::getMinutes() const {
    return minutes;
}

int Time::getSeconds() const {
    return seconds;
}

string &Time::getFormat() {
    return format;
}

 string Time::getFullString() const {
    string fullString;
    if (format == "12h Form") {
        string amOrPm;
        int tmpHours;
        if (hours >= 12)
            amOrPm = "PM";
        else
            amOrPm = "AM";
        tmpHours = (hours > 12 ? hours - 12 : hours);
        fullString =
                std::to_string(tmpHours) + " : " + std::to_string(minutes) + " : " + std::to_string(seconds) + " " +
                amOrPm;
    } else {
        fullString = std::to_string(hours) + " : " + std::to_string(minutes) + " : " + std::to_string(seconds);
    }
    return fullString;
}



