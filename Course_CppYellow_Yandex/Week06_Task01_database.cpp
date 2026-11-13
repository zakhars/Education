#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "Week06_Task01_database.h"

using namespace std;

string ParseEvent(istream& is)
{
    string event;
    while (is.peek() == ' ')
    {
        is.get();
    }
    getline(is, event);
    return event;
}

void Database::addEvent(EventsToDate& e, const string& event)
{
    e.events_by_name.insert(make_pair(event, ++e.max_id));
    e.events_by_id.insert(make_pair(e.max_id, event));
}

void Database::delEvent(EventsToDate& e, const string& event)
{
    auto event_id = e.events_by_name.find(event)->second; // assume existence was already checked
    e.events_by_name.erase(event);
    e.events_by_id.erase(event_id);
}

void Database::Add(const Date& date, const string& event)
{
    auto& e = storage[date]; // will be created if was absent
    if (e.events_by_name.count(event) == 0) // duplicates are ignored
    {
        addEvent(e, event);
    }
}

vector<string> Database::FindIf(std::function<bool(const Date& d, const string& event)> pred) const
{
    vector<string> events_found;

    for (const auto& e : storage)
    {
        const Date& date = e.first;
        const auto& events = e.second.events_by_id;

        for (const auto& event : events)
        {
            if (pred(date, event.second))
            {
                stringstream ss;
                ss << date << " " << event.second;
                events_found.push_back(ss.str());
            }
        }
    }
    return events_found;
}

int Database::RemoveIf(std::function<bool(const Date& d, const string& event)> pred)
{
    int count_removed = 0;

    auto e = storage.begin();
    while(e != storage.end())
    {
        const Date& date = e->first;

        vector<string> events_to_remove;
        auto& events = e->second.events_by_name;
        for (auto& event : events)
        {
            if (pred(date, event.first))
            {
                events_to_remove.push_back(event.first);
            }
        }
        for (auto& event : events_to_remove)
        {
            delEvent(e->second, event);
            ++count_removed;
        }

        if (events.empty())
        {
            e = storage.erase(e);
        }
        else
        {
            ++e;
        }
    }
    return count_removed;
}

string Database::Last(const Date& date) const
{
    const string no_entries = "No entries";
    auto it = storage.lower_bound(date);
    if (storage.empty() || it == begin(storage) && date != it->first)
    {
        return no_entries;
    }

    if (it == end(storage) || date != it->first)
    {
        --it;
    }

    const auto& events = it->second.events_by_id;

    stringstream ss;
    ss << it->first << " " << crbegin(events)->second; // it is impossible that all are removed

    return ss.str();
}

void Database::Print(ostream& os) const
{
    auto pred = [](const Date& date, const string& event) { return true; };
    for (const auto& event : FindIf(pred))
    {
        os << event << endl;
    }
}
