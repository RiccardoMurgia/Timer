//
// Created by riccardo on 11/11/20.
//

#include "Date.h"

Date::Date(int day, int month, int year, int dayOfWeek, bool leapYear) : day(day), month(month), year(year),
                                                                         dayOfWeek(dayOfWeek), leapYear(leapYear) ,format("Extended Format"){}

void Date::setDay(int day) {
    Date::day = day;
}

void Date::setMonth(int month) {
    Date::month = month;
}

void Date::setYear(int year) {
    Date::year = year;
}

void Date::setDayOfWeek(int dayOfWeek) {
    Date::dayOfWeek = dayOfWeek;
}

void Date::setFormat(const string &format) {
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

string &Date::getFormat() {
    return format;
}

bool Date::isLeapYear() {
    return false;
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

    if (format == "DD-MM-YYYY") {
        fullString = d + " " + m + " " + y;
        return fullString;
    } else if (format == "DD-MM-YY") {
        fullString = d + " " + m + " " + y.substr(2, 3);
        return fullString;
    } else {
        string tmp;
        string namesOfWeek[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        tmp = namesOfWeek[dayOfWeek - 1];
        fullString = tmp + ", " + d + " - " + m + " - " + y;
        return fullString;
    }

}






