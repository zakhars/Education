#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>

#include "Week06_Task01_date.h"

using namespace std;

Date::Date(const string& sDate)
{
    if (sDate.find('+') != string::npos) throwWrongDate(sDate);
    stringstream ss(sDate);
    char first_symbol = ss.peek();
    if (first_symbol == '-') throwWrongDate(sDate);
    ss >> year;
    if (!ss.good() || year < 0 || year > 9999) throwWrongDate(sDate);
    char delim = 0;
    ss >> delim;
    if (delim != '-') throwWrongDate(sDate);
    ss >> month;
    if (!ss.good()) throwWrongDate(sDate);
    delim = 0;
    ss >> delim;
    if (delim != '-') throwWrongDate(sDate);
    ss >> day;
    if (ss.bad() || ss.fail() || !ss.eof()) throwWrongDate(sDate);

    if (month < 1 || month > 12) throw invalid_argument("Month value is invalid: " + to_string(month));
    if (day < 1 || day > 31) throw invalid_argument("Day value is invalid: " + to_string(day));
}

void Date::throwWrongDate(const std::string& sDate) const
{
    throw std::invalid_argument("Wrong date format: " + sDate);
}

bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() < rhs.GetYear()) return true;
    if (lhs.GetYear() > rhs.GetYear()) return false;
    if (lhs.GetMonth() < rhs.GetMonth()) return true;
    if (lhs.GetMonth() > rhs.GetMonth()) return false;
    return lhs.GetDay() < rhs.GetDay();
}

bool operator==(const Date& lhs, const Date& rhs)
{
    return lhs.GetYear() == rhs.GetYear() &&
           lhs.GetMonth() == rhs.GetMonth() &&
           lhs.GetDay() == rhs.GetDay();
}

bool operator<=(const Date& lhs, const Date& rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator>(const Date& lhs, const Date& rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const Date& lhs, const Date& rhs)
{
    return lhs > rhs || lhs == rhs;
}

bool operator!=(const Date& lhs, const Date& rhs)
{
    return !(lhs == rhs);
}

ostream& operator<< (ostream& os, const Date& date)
{
    os  << setw(4) << setfill('0') << date.GetYear() << '-'
        << setw(2) << setfill('0') << date.GetMonth() << '-'
        << setw(2) << setfill('0') << date.GetDay();
    return os;
}

istream& operator>> (istream& is, Date& date)
{
    string sdate;
    is >> sdate;
    date = Date{ sdate };
    return is;
}

Date ParseDate(istream& is)
{
    Date date;
    is >> date;
    return date;
}
