#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include "airline_ticket.h"
#include "test_runner.h"


using namespace std;

#define UPDATE_FIELD(ticket, field, values) \
{ \
    map<string, string>::const_iterator it = values.find(#field); \
    if (it != end(values)) { istringstream is(it->second); is >> ticket.field; }  \
}

bool operator==(const Date& lhs, const Date& rhs)
{
    return tie(lhs.year, lhs.month, lhs.day) ==
        tie(rhs.year, rhs.month, rhs.day);
}

istream& operator>>(istream& is, Date& d)
{
    is >> d.year;
    is.ignore(1);
    is >> d.month;
    is.ignore(1);
    is >> d.day;
    return is;
}

ostream& operator<<(ostream& os, const Date& d)
{
    os << d.year << "-" << d.month << "-" << d.day;
    return os;
}

bool operator==(const Time& lhs, const Time& rhs)
{
    return tie(lhs.hours, lhs.minutes) ==
        tie(rhs.hours, rhs.minutes);
}

istream& operator>>(istream& is, Time& t)
{
    is >> t.hours;
    is.ignore(1);
    is >> t.minutes;
    return is;
}

ostream& operator<<(ostream& os, const Time& t)
{
    os << t.hours << ":" << t.minutes;
    return os;
}

void TestUpdate() {
    AirlineTicket t;
    t.price = 0;

    const map<string, string> updates1 = {
        { "departure_date", "2018-2-28" },
        { "departure_time", "17:40" },
    };
    UPDATE_FIELD(t, departure_date, updates1);
    UPDATE_FIELD(t, departure_time, updates1);
    UPDATE_FIELD(t, price, updates1);

    ASSERT_EQUAL(t.departure_date, (Date{ 2018, 2, 28 }));
    ASSERT_EQUAL(t.departure_time, (Time{ 17, 40 }));
    ASSERT_EQUAL(t.price, 0);

    const map<string, string> updates2 = {
        { "price", "12550" },
        { "arrival_time", "20:33" },
    };
    UPDATE_FIELD(t, departure_date, updates2);
    UPDATE_FIELD(t, departure_time, updates2);
    UPDATE_FIELD(t, arrival_time, updates2);
    UPDATE_FIELD(t, price, updates2);

    // updates2 �� �������� ������ "departure_date" � "departure_time", �������
    // �������� ���� ����� �� ������ ����������
    ASSERT_EQUAL(t.departure_date, (Date{ 2018, 2, 28 }));
    ASSERT_EQUAL(t.departure_time, (Time{ 17, 40 }));
    ASSERT_EQUAL(t.price, 12550);
    ASSERT_EQUAL(t.arrival_time, (Time{ 20, 33 }));
}

int main_cppr_w1_t4() {
    TestRunner tr;
    RUN_TEST(tr, TestUpdate);
    return 0;
}

// Teacher's solution:

#define UPDATE_FIELD1(ticket, field, values) \
  {                                         \
    auto it = values.find(#field);          \
    if (it != values.end()) {               \
      istringstream is(it->second);         \
      is >> ticket.field;                   \
    }                                       \
  }