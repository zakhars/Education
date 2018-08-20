#include <iostream>
#include <map>
#include <cctype>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iomanip>
using namespace std;
namespace
{
    class Date
    {
        int month = -1; // [1..12]
        int day = -1;   // [1..31]
        int year = -1;  // [0..9999]

        void throwWrongDate(const string& sDate) const
        {
            throw invalid_argument("Wrong date format: " + sDate);
        }


    public:
        int GetYear() const { return year; }
        int GetMonth() const { return month; }
        int GetDay() const { return day; }

        Date() {}

        explicit Date(const string& sDate)
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
    };

    bool operator<(const Date& lhs, const Date& rhs)
    {
        if (lhs.GetYear() < rhs.GetYear()) return true;
        if (lhs.GetYear() > rhs.GetYear()) return false;
        if (lhs.GetMonth() < rhs.GetMonth()) return true;
        if (lhs.GetMonth() > rhs.GetMonth()) return false;
        return lhs.GetDay() < rhs.GetDay();
    }

    ostream& operator<< (ostream& os, const Date& date)
    {
        os << setw(4) << setfill('0') << date.GetYear() << '-'
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

    class Database
    {
        map<Date, set<string>> storage;
    public:
        void AddEvent(const Date& date, const string& event)
        {
            storage[date].insert(event);
        }

        bool DeleteEvent(const Date& date, const string& event)
        {
            if (storage.count(date) > 0 && storage.at(date).count(event) > 0)
            {
                storage[date].erase(event);
                if (storage[date].size() == 0) // removed last event of date
                {
                    storage.erase(date);
                }
                return true;
            }
            return false;
        }

        size_t DeleteDate(const Date& date)
        {
            if (storage.count(date) == 0) return 0;
            size_t deleted = storage.at(date).size();
            storage.at(date).clear();
            return deleted;
        }

        vector<string> Find(const Date& date) const
        {
            vector<string> events;

            if (storage.count(date) > 0)
            {
                for (const auto& e : storage.at(date))
                {
                    events.push_back(e);
                }
            }
            return std::move(events);
        }

        void Print() const
        {
            for (const auto& date : storage)
            {
                for (const auto& e : date.second)
                {
                    cout << date.first << " " << e << endl;
                }
            }
        }
    };

    void ExecuteCommand(const string& command, Database& db)
    {
        if (command.find_first_not_of(" \t") == string::npos) return;
        istringstream ss(command);
        string cmd_code;
        ss >> cmd_code;
        if (cmd_code == "Add")
        {
            Date date;
            ss >> date;
            if (ss.eof())
            {
                throw invalid_argument("Unknown command: " + command);
            }
            string event;
            ss >> event;
            if (event.find_first_not_of(" \t") == string::npos)
            {
                throw invalid_argument("Unknown command: " + command);
            }
            db.AddEvent(date, event);
        }
        else if (cmd_code == "Del")
        {
            Date date;
            ss >> date;
            string event;
            if (ss >> event && event != "") // delete specific event
            {
                if (db.DeleteEvent(date, event))
                {
                    cout << "Deleted successfully" << endl;
                }
                else
                {
                    cout << "Event not found" << endl;
                }
            }
            else // delete by date
            {
                cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
            }
        }
        else if (cmd_code == "Find")
        {
            Date date;
            ss >> date;
            vector<string> events = db.Find(date);
            for (const auto& e : events)
            {
                cout << e << endl;
            }
        }
        else if (cmd_code == "Print")
        {
            db.Print();
        }
        else
        {
            throw invalid_argument("Unknown command: " + cmd_code);
        }
    }
}

int main_05_01()
{
	Database db;
    //ifstream fin("d:\\q");
    istream& in = cin;
	string command;
	while (getline(in, command))
	{
		if (command == "")  continue;
		try
		{
			ExecuteCommand(command, db);
		}
		catch(const exception& ex)
		{
			cout << ex.what() << endl;
			return -1;
		}
	}

	return 0;
}
