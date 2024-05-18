/*
You will be given an array of N integers and you have to print the integers in the reverse order.

Input Format:
The first line of the input contains ,where  is the number of integers.The next line contains  space-separated integers.

Output Format:
Print the  integers of the array in the reverse order, space-separated on a single line.
*/

#include <vector>
#include <iostream>

int main() 
{
    // length of array
    int length{};
    std::cin >> length;

    // initializing my array. std::vector does dynamic allocation 
    std::vector<int> arr(length);

    // filling my array
    for (int i{0}; i < length; i++)
    {
        std::cin >> arr[i];
    }

    // printing my array
    for (int i{length-1}; i >= 0; i--)
    {
        std::cout << arr[i] << " ";
    }

    */
    // using iterators
    for (auto it {arr.begin()}; it != arr.end(); ++it)
    {
        std::cin >> *it;
    }

    for (auto it {std::end(arr) - 1}; it != (arr.begin() -1); --it )
    {
        std::cout << *it << " ";
    }

    //using reverse iterators to print
    std::cout << "\n";
    for (auto it {arr.rbegin()}; it != arr.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    /*
        
    return 0;
}
