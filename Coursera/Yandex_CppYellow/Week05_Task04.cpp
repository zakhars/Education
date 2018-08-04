#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <memory>
#include <cmath>

using namespace std;

//Реализуйте недостающие функции и классы :
//
//- базовый класс Figure с чисто виртуальными методами Name, Perimeter и Area;
//- классы Triangle, Rect и Circle, которые являются наследниками класса Figure и переопределяют его виртуальные методы;
//- функцию CreateFigure, которая в зависимости от содержимого входного потока создаёт 
//  shared_ptr<Rect>, shared_ptr<Triangle> или shared_ptr<Circle>.
//
//Гарантируется, что все команды ADD корректны; размеры всех фигур — это натуральные числа не больше 1000. 
//В качестве значения π используйте 3.14.

class Figure
{
    const string name_;
public:
    Figure(string name) : name_(name) {}
    string Name() const { return name_; }
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure
{
    double a_, b_, c_;
public:
    Triangle(double a, double b, double c) :
        a_(a), b_(b), c_(c), Figure("TRIANGLE")
    {
    }
    double Perimeter() const override
    {
        return a_ + b_ + c_;
    }
    double Area() const override
    {
        double p = Perimeter() / 2.0;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }
};

class Circle : public Figure
{
    double r_;
public:
    Circle(double r) : r_(r), Figure("CIRCLE") {}
    double Perimeter() const override
    {
        return 2 * 3.14 * r_;
    }
    double Area() const override
    {
        return 3.14 * r_ * r_;
    }
};



class Rect : public Figure
{
    double w_, h_;
public:
    Rect(double w, double h) : w_(w), h_(h), Figure("RECT") {}
    double Perimeter() const override
    {
        return 2 * w_ + 2 * h_;
    }
    double Area() const override
    {
        return w_ * h_;
    }
};

shared_ptr<Figure> CreateFigure(istream& is)
{
    string name;
    is >> name;
    if (name == "TRIANGLE")
    {
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }
    if (name == "CIRCLE")
    {
        double r;
        is >> r;
        return make_shared<Circle>(r);
    }
    if (name == "RECT")
    {
        double w, h;
        is >> w >> h;
        return make_shared<Rect>(w, h);
    }
    return nullptr;
}

int main_cppy_w5_t5() 
{
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}