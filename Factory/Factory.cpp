#include <map>
#include <functional>
#include <iostream>
#include <complex>
#include <vector>
#include <memory>
using namespace std;

struct Shape
{
    virtual void draw() = 0;
};

struct Circle : public Shape
{
    Circle(istream &is) { is >> p >> r; }
    virtual void draw() { cout << "C " << p << " " << r; }
    complex<double> p;
    double r;
};

struct Rectangle : public Shape
{
    Rectangle (istream &is) { is >> p1 >> p2; }
    virtual void draw() { cout << "R " << p1 << " " << p2; }
    complex<double> p1;
    complex<double> p2;
};

auto shapeData = R"(
rectangle (0, 0) (1, 1)
circle (0, 0) 2
rectangle (-1, 1) (10,4.2)
)";

class ShapeFactory
{
public:
    unique_ptr<Shape> load(string const &type, istream &is)
    {
        auto it = creators.find(type);
        if(it != creators.end())
        {
            return it->second(is);
        }
        return unique_ptr<Shape>();
    }
    map < string, function<unique_ptr<Shape>(istream&)>> creators;
};

auto shapeFactory = ShapeFactory{ {
    {"circle", [](istream &is) {return make_unique<Circle>(is); } },
    {"rectangle", [](istream &is) {return make_unique<Rectangle>(is); } },
} };

vector<unique_ptr<Shape>> load(istream &is)
{
    vector<unique_ptr<Shape>> result;
    while (is)
    {
        string type;
        is >> type;
        auto shape = shapeFactory.load(type, is);
        if (shape)
        {
            result.push_back(move(shape));
        }
    }
    return result;
}


int main()
{
    istringstream iss(shapeData);
    auto shapes = load(iss);
    for (auto const &shape : shapes)
    {
        shape->draw();
        cout << endl;
    }
}
