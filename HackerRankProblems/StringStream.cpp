/*
Given a string of comma delimited integers, return a vector of integers.

parseInts has the following parameters:

string str: a string of comma separated integers
Returns

vector<int>: a vector of the parsed integers.

*/


#include <sstream>
#include <vector>
#include <iostream>


std::vector<int> parseInts(std::string str) //str = "23,4,56"
{
    std::vector <int> myVect{};
    std::string temp{};

    for (int i=0; i < str.length() ; ++i)
    {
        temp += str[i];

        if ( (str[i] == ',') || (i == (str.length() - 1)) )
        {
            myVect.emplace_back(std::stoi(temp));
            temp = "";
        }
    }
    return myVect;
}

int main()
{
    std::string str;
    std::cin >> str;    // "23,4,56"
    std::vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        std::cout << integers[i] << "\n";
    }

    return 0;
}
