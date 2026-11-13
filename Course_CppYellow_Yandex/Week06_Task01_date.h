#pragma once

#include <iostream>
#include <string>

class Date
{
    int month = -1; // [1..12]
    int day = -1;   // [1..31]
    int year = -1;  // [0..9999]

    void throwWrongDate(const std::string& sDate) const;

public:
    int GetYear() const { return year; }
    int GetMonth() const { return month; }
    int GetDay() const { return day; }

    Date() {}
    Date(int year, int month, int day) : year(year), month(month), day(day) {}
    explicit Date(const std::string& sDate);
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);

std::ostream& operator<< (std::ostream& os, const Date& date);
std::istream& operator>> (std::istream& is, Date& date);

Date ParseDate(std::istream& is);
