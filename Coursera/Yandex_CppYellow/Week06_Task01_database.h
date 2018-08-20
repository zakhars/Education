#pragma once

#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <functional>

#include "Week06_Task01_date.h"

std::string ParseEvent(std::istream& is);

class Database
{
    struct EventsToDate
    {
        std::unordered_map<std::string, int> events_by_name;
        std::map<int, std::string> events_by_id;
        int max_id = -1;
    };
    std::map<Date, EventsToDate> storage;

    void addEvent(EventsToDate& e, const std::string& event);
    void delEvent(EventsToDate& e, const std::string& event);

public:
    void Add(const Date& date, const std::string& event);
    std::vector<std::string> FindIf(std::function<bool(const Date& d, const std::string& event)> pred) const;
    int RemoveIf(std::function<bool(const Date& d, const std::string& event)> pred);
    std::string Last(const Date& date) const;
    void Print(std::ostream& os) const;
};
