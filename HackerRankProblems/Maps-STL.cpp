/*
Problem:
https://www.hackerrank.com/challenges/cpp-maps/problem?isFullScreen=true
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

int main()
{

    // num of queries
    int n{};
    std::cin >> n;

    std::string name{};
    int mark{};
    int choice{};

    std::map <std::string, int> my_map{};

    for (int i{0}; i < n; i++)
    {
        std::cin >> choice >> name;
        auto it {my_map.find(name)};

        if (choice == 1) //add student
        {
            std::cin >> mark;
            if (it != my_map.end() )     // if student is found, add to the mark (key)
                it->second += mark;

            else                        // if student is not found, add the student and mark
                my_map.insert(make_pair(name,mark));
        }

        else if (choice == 2)    //erase student mark (key)
        {
            //search for student based on key (name)
            if (it != my_map.end()) //if student is found, erase it
                my_map.erase(name);
        }

        else if (choice == 3)    //Print mark of student, if not found print 0
        {
            if (it != my_map.end()) //if student is found, erase it
                std::cout << it->second << "\n";
            else
                std::cout << 0 << "\n";
        }
    }

    return 0;
}
