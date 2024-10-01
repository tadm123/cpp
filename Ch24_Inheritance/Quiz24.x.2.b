/*
Add a new class to the previous program called GrannySmith that inherits from Apple.
*/

#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
private:
    std::string m_name{};
    std::string m_color{};

public:
    Fruit (std::string_view name = "", std::string_view color = "")
        : m_name {name}, m_color {color}
    {
    }

    std::string_view getName() { return m_name; }
    std::string_view getColor() { return m_color; }

};

class Apple : public Fruit
{
public:
    Apple(std::string_view color = "red")
        : Fruit { "apple", color }
    {
    }

    Apple(std::string_view name, std::string_view color)
        : Fruit{name, color}
    {
    }

};


class Banana : public Fruit
{
public:
    Banana()
        : Fruit { "banana", "yellow" }
    {
    }

};

class GrannySmith: public Apple
{
public:
    GrannySmith()
    : Apple{"granny smith apple", "green"}
    {
    }

};

int main()
{
    Apple a{ "red" };
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
