/*
In the first line print two space-separated integers, representing the length of a and b respectively.
In the second line print the string produced by concatenating a and b.
In the third line print two strings separated by a space, a'  and a'. a' and a' are the same as a and b, respectively, except that their first characters are swapped
*/

#include <iostream>
#include <string>
#include <string_view>

void myFunction(std::string& s1, std::string& s2)
{
    //print two space-separated integers reprersenting the length
    std::cout << s1.size() << " " << s2.size() << "\n";


    //concatanate
    std::cout << s1+s2 << "\n";

    //swap 1st element
    char temp{s2[0]};
    s2[0] = s1[0];
    s1[0] = temp;

    std::cout << s1 << " " << s2 << "\n";

}

int main()
{

    //type two strings
    std::string s1{};
    std::string s2{};

    std::cin >> s1;
    std::cin >> s2;

    myFunction(s1,s2);

    return 0;
}
