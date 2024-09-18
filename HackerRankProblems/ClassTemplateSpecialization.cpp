/*
  You are given a main function which reads the enumeration values for two different types as input, 
  then prints out the corresponding enumeration names. Write a class template that can provide the names 
  of the enumeration values for both types. If the enumeration value is not valid, then print unknown.
*/


#include <iostream>
#include <string>
#include <array>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template<>
struct Traits<Fruit>
{
    static std::string name(int index)
    {
        if (index > 2 || index < 0)
            return "unknown";

        using namespace std::string_literals;
        std::array <std::string, 3> fruit_names { "apple"s, "orange"s, "pear"s };

        return fruit_names[index];
    }

};

template<>
struct Traits<Color>
{
    static std::string name(int index)
    {
        if (index > 2 || index < 0)
            return "unknown";

        using namespace std::string_literals;
        std::array <std::string, 3> color_names { "red"s, "green"s, "orange"s };

        return color_names[index];
    }
};


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
