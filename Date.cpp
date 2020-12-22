//
// Created by riccardo on 11/11/20.
//

#include "Date.h"

Date::Date(int day, int month, int year, int dayOfWeek, bool leapYear, DataFormat format) : day(day), month(month),
                                                                                        year(year),
                                                                                        dayOfWeek(dayOfWeek),
                                                                                        leapYear(leapYear),
                                                                                        format(format) {}

void Date::setDay(int day) {
    if (day > 0 && day <= 31)
        Date::day = day;
    else
        throw  std::invalid_argument("Invalid day");
}

void Date::setMonth(int month) {
    if (month > 0 && month <= 12)
        Date::month = month;
    else
        throw  std::invalid_argument("Invalid month");
}

void Date::setYear(int year) {
    if (year >= 0)
        Date::year = year;
    else
        throw  std::invalid_argument("Invalid year");
}

void Date::setDayOfWeek(int dayOfWeek) {
    if (dayOfWeek >= 0 && dayOfWeek <= 6)
        Date::dayOfWeek = dayOfWeek;
    else
        throw  std::invalid_argument("Invalid dayOfWeek");
}

void Date::setLeapWeek(bool isLeapWeek) {
    leapYear = isLeapWeek;
}


void Date::setFormat(const DataFormat &format) {
    Date::format = format;
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

DataFormat &Date::getFormat() {
    return format;
}

bool Date::isLeapYear() {
    return leapYear;
}

bool Date::checkIfIsALeapYear(int year) {
    bool isLeapYear = false;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                isLeapYear = true;
            } else {
                isLeapYear = false;
            }
        } else {
            isLeapYear = true;
        }
    } else {
        isLeapYear = false;
    }
    return isLeapYear;

}

string Date::getFullString() const {
    string fullString, d, m, y;
    if (day < 10) {
        d = "0" + std::to_string(day);
    } else {
        d = std::to_string(day);
    }
    if (month < 10) {
        m = "0" + std::to_string(month);
    } else {
        m = std::to_string(month);
    }
    y = std::to_string(year);

    if (format == 1) {
        fullString = d + " - " + m + " - " + y;
        return fullString;
    } else if (format == 2) {
        fullString = d + " - " + m + " - " + y.substr(2, 3);
        return fullString;
    } else {
        string tmp;
        string namesOfWeek[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        tmp = namesOfWeek[dayOfWeek - 1];
        fullString = tmp + ", " + d + " - " + m + " - " + y;
        return fullString;
    }

}

int Date::getDayOfWeek() const {
    return dayOfWeek;
}





