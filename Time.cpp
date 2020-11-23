//
// Created by riccardo on 11/11/20.
//

#include "Time.h"

Time::Time(int hours, int minutes, int seconds, string format) : hours(hours), minutes(minutes), seconds(seconds),
                                                                 format(format) {}

void Time::setHours(int hours) {
    if (hours >= 0 && hours <= 23)
        Time::hours = hours;
    else
        hours = 0;
}

void Time::setMinutes(int minutes) {
    if (minutes >= 0 && minutes <= 59)
        Time::minutes = minutes;
    else
        minutes = 0;
}

void Time::setSeconds(int seconds) {
    if (seconds >= 0 && seconds <= 59)
        Time::seconds = seconds;
    else
        seconds = 0;
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
        fullString = h + " : " + min + " : " + sec + " " + amOrPm;
    } else {
        fullString = h + " : " + min + " : " + sec;
    }
    return fullString;
}




