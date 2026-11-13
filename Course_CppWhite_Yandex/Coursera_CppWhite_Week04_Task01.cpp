#include <iostream>
#include <string>
using namespace std;

struct Specialization
{
	string s;
	explicit Specialization(string& s) : s(s) {}
};

struct Course
{
	string c;
	explicit Course(string& c) : c(c) {}
};

struct Week
{
	string w;
	explicit Week(string& w) : w(w) {}
};

struct LectureTitle
{
  string specialization;
  string course;
  string week;

  LectureTitle(const Specialization& s, const Course& c, const Week& w)
  {
	  specialization = s.s;
	  course = c.c;
	  week = w.w;
  }
};


