/*
Print the integers in the sorted order one by one in a single line followed by a space.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main()
{

    //size of array
    int size{};
    std::cin >> size;
    std::vector<int> myVect;

    for (int i{0}; i < size; ++i)
    {
        int x{0};
        std::cin >> x;
        myVect.push_back(x);
    }

    //sort by order
    std::sort( myVect.begin(), myVect.end() );

    //print integers one by one
    for (const auto& element: myVect)
    {
        std::cout << element << " ";
    }

    return 0;
}
