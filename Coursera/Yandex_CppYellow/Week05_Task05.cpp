#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base people properties
class People {
protected:
    string name_;
    const string title_;

    void walkCommon(const string& destination)  {
        cout << Title() << ": " << Name() << " walks to: " << destination << endl;
    }

public:
    People(const string& name, const string& title) 
        : name_(name)
        , title_(title) {
    }

    string Name() const { return name_;  }

    virtual void Walk(const string& destination) { walkCommon(destination); }

    string Title() const { return title_; }

};

class Student : public People {
public:

    Student(string name, string favoriteSong) 
        : People(name, "Student")
        , favoriteSong_(favoriteSong) {
    }

    void Learn() const {
        cout << Title() << ": " << Name() << " learns" << endl;
    }

    void Walk(const string& destination) override {
        People::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        cout << Title() << ": " << Name() << " sings a song: " << favoriteSong_ << endl;
    }
protected: // probably not a final class
    string favoriteSong_;
};


class Teacher : public People {
public:

    Teacher(const string& name, const string& subject) 
        : People(name, "Teacher")
        , subject_(subject) {
    }

    void Teach() const {
        cout << Title() << ": " << Name() << " teaches: " << subject_ << endl;
    }

protected:
    string subject_;
};


class Policeman : public People {
public:
    Policeman(string name) 
        : People(name, "Policeman") {
    }

    void Check(const People& t) {
        cout << Title() << ": " << Name() << " checks " << t.Title() << ". " << t.Title() << "'s name is: " << t.Name() << endl;
    }
};


void VisitPlaces(People& t, vector<string> places) {
    for (auto p : places) {
        t.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");
    Policeman p2("Sherlock");

    VisitPlaces(t, { "Moscow", "London" });
    VisitPlaces(s, { "Moscow", "London" });
    VisitPlaces(p, { "London", "Moscow" });

    p.Check(s);
    p.Check(t);
    p.Check(p2);

    s.Learn();
    s.SingSong();

    t.Teach();

    return 0;
}
