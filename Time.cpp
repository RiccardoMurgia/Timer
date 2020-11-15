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
    std::string sec = std::to_string(seconds);
    std::string min = std::to_string(minutes);
    std::string h = std::to_string(hours);
    if (seconds < 10)
        sec = '0' + std::to_string(seconds);
    if (minutes < 10)
        min = '0' + std::to_string(minutes);
    if (hours < 10)
        h = '0' + std::to_string(hours);
    if (format == "12h Form") {
        string amOrPm;
        int tmpHours;
        if (hours >= 12)
            amOrPm = "PM";
        else
            amOrPm = "AM";
        tmpHours = (hours > 12 ? hours - 12 : hours);
        if (tmpHours < 10)
            h = "0" + std::to_string(tmpHours);
        fullString = h + " : " + min+ " : " + sec+ " " + amOrPm;
    } else {
        fullString = h + " : " + min + " : " + sec;
    }
    return fullString;
}



