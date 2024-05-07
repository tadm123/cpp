/*

You will be given two positive integers, a and b  (a <= b), separated by a newline.
For each integer  in the inclusive interval [a,b):

If 1 < n <= 9, then print the English representation of it in lowercase. That is "one" for , "two" for , and so on.
Else if n > 9 and it is an even number, then print "even".
Else if n > 9 and it is an odd number, then print "odd".

*/


#include <iostream>
#include <string>


std::string printNumber(int x)
{
    switch(x)
    {
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        default: break;
    }

    if (x % 2 == 0)
        return "even";

    else
        return "odd";

}

int main()
{
    int a{};
    int b{};

    std::cin >> a;
    std::cin >> b;

    for (int i{a}; i <= b; i++)
        std::cout << printNumber(i) << '\n';

    return 0;
}
