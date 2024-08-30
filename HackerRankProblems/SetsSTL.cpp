/*
  The first line of the input contains Q where Q is the number of queries. 
  The next Q lines contain 1 query each. Each query consists of two integers y and x where  is the type of the query and x is an integer.

  For queries of type 3 print "Yes"(without quotes) if the number x is present in the set and if the number is not present, then print "No"(without quotes).
  Each query of type 3 should be printed in a new line.
*/


#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>


int main()
{

    std::set <int> s{};
    int num{};
    int length{};
    int choice;


    std::cin >> length;


    for (int i{0}; i < length; i++)
    {
        std::cin >> choice >> num;

        //if 1 -> insert
        if (choice == 1)
        {
            s.insert(num);
        }
        else        //if 2 or 3
        {
            auto it{s.find(num)};

            if (choice == 2)    //if 2 -> delete
            {
                if (it != s.end()) //if number is found
                {
                    s.erase(num);
                }
            } else if (choice == 3) {
                if (it != s.end()) //if number is found -> print Yes
                    std::cout << "Yes\n";
                else                //if number is not found -> print No
                    std::cout << "No\n";
            }
        }
    }

    return 0;
}
