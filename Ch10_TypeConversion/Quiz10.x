/* Upgrade the following program using type aliases (https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/) */

#include <iostream>

namespace constants
{
    inline constexpr double pi { 3.14159 };
}

double convertToRadians(double degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    using Degrees = double;

    std::cout << "Enter a number of degrees: ";
    Degrees degrees{};
    std::cin >> degrees;

    using Radians = double;
    Radians radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}
