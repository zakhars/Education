#pragma once

#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <algorithm>
//#include "phone_number.h"

using namespace std;

class PhoneNumber {
public:
    /* Принимает строку в формате +XXX-YYY-ZZZZZZ
    Часть от '+' до первого '-' - это код страны.
    Часть между первым и вторым символами '-' - код города
    Всё, что идёт после второго символа '-' - местный номер.
    Код страны, код города и местный номер не должны быть пустыми.
    Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.

    Примеры:
    * +7-495-111-22-33
    * +7-495-1112233
    * +323-22-460002
    * +1-2-coursera-cpp
    * 1-2-333 - некорректный номер - не начинается на '+'
    * +7-1233 - некорректный номер - есть только код страны и города
    */
    explicit PhoneNumber(const string &international_number);

    string GetCountryCode() const;
    string GetCityCode() const;
    string GetLocalNumber() const;
    string GetInternationalNumber() const;

private:
    string country_code_;
    string city_code_;
    string local_number_;
};

PhoneNumber::PhoneNumber(const string& international_number)
{
    const string& num = international_number;
    if (num.size() < string("+N-N-N").size() || num[0] != '+' || count(begin(num), end(num), '-') < 2)
    {
        throw invalid_argument(num);
    }

    size_t delim1_pos = num.find('-', 0);
    if (delim1_pos == 1)
    {
        throw invalid_argument(num);
    }
    size_t delim2_pos = num.find('-', delim1_pos + 1);
    if (delim2_pos == delim1_pos + 1)
    {
        throw invalid_argument(num);
    }
    copy(&num[1], &num[delim1_pos], back_inserter(country_code_));
    copy(&num[delim1_pos + 1], &num[delim2_pos], back_inserter(city_code_));
    local_number_ = num.substr(delim2_pos + 1);
}

string PhoneNumber::GetCountryCode() const
{
    return country_code_;
}

string PhoneNumber::GetCityCode() const
{
    return city_code_;
}
string PhoneNumber::GetLocalNumber() const
{
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
    ostringstream oss;
    oss << '+' << GetCountryCode() << '-' << GetCityCode() << '-' << GetLocalNumber();
    return oss.str();
}

int main_w03_t02()
{
    PhoneNumber p1("+7 - 495 - 111 - 22 - 33");
    cout << p1.GetInternationalNumber() << endl;
    PhoneNumber p2("+7 - 495 - 1112233");
    cout << p2.GetInternationalNumber() << endl;
    PhoneNumber p3("+323 - 22 - 460002");
    cout << p3.GetInternationalNumber() << endl;
    PhoneNumber p4("+1 - 2 - coursera - cpp");
    cout << p4.GetInternationalNumber() << endl;
    try
    {
        PhoneNumber p5("1 - 2 - 333");
    }
    catch (invalid_argument)
    {
        cout << "p5";
    }
    try
    {
        PhoneNumber p6("+7 - 1233");
    }
    catch (invalid_argument)
    {
        cout << "p6";
    }
    return 0;

}

// Teacher's solution:

/*
#include <stdexcept>
#include <string>
#include <sstream>
#include "phone_number.h"

using namespace std;

PhoneNumber::PhoneNumber(const string& international_number) {
  istringstream is(international_number);

  char sign = is.get();
  getline(is, country_code_, '-');
  getline(is, city_code_, '-');
  getline(is, local_number_);

  if (sign != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
    throw invalid_argument("Phone number must begin with '+' symbol and contain 3 parts separated by '-' symbol: " + international_number);
  }
}

string PhoneNumber::GetCountryCode() const {
  return country_code_;
}

string PhoneNumber::GetCityCode() const {
  return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
  return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
  return ("+" + country_code_ + "-" + city_code_ + "-" + local_number_);
}

*/