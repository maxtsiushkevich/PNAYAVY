//Создать абстрактный класс Точка. 
//Получить производный класе Круг и реализовать функцию вычисления площади круга
//Получить производный класс Цилиндр (наследуется от класса Круг) и
//реализовать функцию вычисления площади поверхности и объема цилиндра.
//Использовать конструктор с параметрами, виртуальный деструктор.

#include <iostream>

using namespace std;

class Point
{
public:
    Point() = default;
    virtual ~Point() = 0;
};

Point :: ~Point() { }

class Circle : public Point
{
protected:
    float radius;
public:
    virtual float Area()
    {
        return radius * 3.14 * 3.14;
    }

    Circle(float radius) : Point()
    {
        this->radius = radius;
    }
    ~Circle() = default;
};

class Cylinder : public Circle
{
protected:
    float height;
public:
    Cylinder(float radius, float height) : Circle(radius)
    {
        this->height = height;
    }
    float Area()
    {
        return (Circle::Area() * 2) + (height * radius * 2 * 3.14);
    }
    float Volume()
    {
        return Circle::Area() * height;
    }
};

int main()
{
    Circle a(5);
    cout << a.Area();
}
