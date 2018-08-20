#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base people properties
class People {
protected:
    const string name_;
    const string title_;

    const string fullName() const {
        return Title() + ": " + Name();
    }

    void doWalk(const string& destination) const  {
        cout << fullName() << " walks to: " << destination << endl;
    }

public:
    People(const string& name, const string& title) 
        : name_(name)
        , title_(title) {
    }

    const string& Name() const { return name_;  }
    const string& Title() const { return title_; }
    virtual void Walk(const string& destination) const { doWalk(destination); }
};

class Student : public People {
public:

    Student(const string& name, const string& favoriteSong) 
        : People(name, "Student")
        , favoriteSong_(favoriteSong) {
    }

    void Learn() const {
        cout << fullName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        People::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        cout << fullName() << " sings a song: " << favoriteSong_ << endl;
    }
protected: // probably not a final class
    const string favoriteSong_;
};


class Teacher : public People {
public:

    Teacher(const string& name, const string& subject) 
        : People(name, "Teacher")
        , subject_(subject) {
    }

    void Teach() const {
        cout << fullName() << " teaches: " << subject_ << endl;
    }

protected:
    const string subject_;
};


class Policeman : public People {
public:
    Policeman(const string& name) 
        : People(name, "Policeman") {
    }

    void Check(const People& t) const {
        cout << fullName() << " checks " << t.Title()
             << ". " << t.Title() << "'s name is: " << t.Name() << endl;
    }
};


void VisitPlaces(People& t, const vector<string>& places) {
    for (const auto& p : places) {
        t.Walk(p);
    }
}

int main_cppy_w05_t05() {
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
