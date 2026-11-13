#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Student
{
	string name;
	string family_name;
	string year;
	string month;
	string day;
};

void HandleBadInput()
{
	cout << "bad request" << endl;
}

int main_04_06()
{
	int n;
	cin >> n;
	vector<Student> students(n);
	for (int i = 0; i < n; i++)
	{
		Student& s = students[i];
		cin >> s.name >> s.family_name >> s.day >> s.month >> s.year;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string query;
		cin >> query;
		size_t num;
		cin >> num;
		if (num > students.size() || num < 1)
		{
			HandleBadInput();
			continue;
		}
		num--;
		if (query == "name")
		{
			const Student& s = students[num];
			cout << s.name << " " << s.family_name << endl;
		}
		else if (query == "date")
		{
			const Student& s = students[num];
			cout << s.day << "." << s.month << "." << s.year << endl;
		}
		else
		{
			HandleBadInput();
		}
	}

	return 0;
}
