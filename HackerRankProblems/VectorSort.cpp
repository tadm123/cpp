/*
You are given N integers.Sort the N integers and print the sorted order. 
Store the N integers in a vector.Vectors are sequence containers representing arrays that can change in size.
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main()
{

    int length;
    std::cin >> length;

    std::vector <int> arr(length);

    for (int i{0}; i < length; i++)
    {
        std::cin >> arr[i];
    }
    

    std::sort(arr.begin(), arr.end());

    for (const auto& a: arr)
    {
        std::cout << a << " ";
    }

    return 0;
}
