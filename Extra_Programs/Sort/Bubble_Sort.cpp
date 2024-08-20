/* 
Bubble Sort: 

Compares two elements from start to end, if element A is greater than B, swap them.  

Time complexity: Best: O(n), Worse: O(n^2)
Space comlexity: O(1)
*/

#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[] = {10,4,2,5};

    int length{ sizeof(array)/sizeof(array[0]) }; 


    //number of iterations
    for (int i{0}; i < length; i++)
    {
        bool swapped = false; //flag to terminate program if there aren't any more swaps
        for (int j{0}; j < length - 1; j++) //We want to stop it before each reaches the last element, since the last element doesn't have a next lement to compare it with
        {
            //comparing the current element vs the next element
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                /* We can use temporary variables as below, but std::swap is faster since it applies move semantics
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                */
            }
        }
    }


    for(const auto &a:array)
    {
        std::cout << a << " ";
    }

    return 0;
}


/* Optmized bubble sort, terminating the search early if there are no more swaps to be made:
#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[] = {10,4,2,5};
    int length{ sizeof(array)/sizeof(array[0]) }; //length of array, since its not c++ std::array, can't use array.size() method

    //number of iterations
    for (int i{0}; i < length; i++)
    {
        bool swapped = false;  //flag to terminate program if there aren't any more swaps, default it as false
        for (int j{0}; j < length - 1; j++) //We want to stop it before each reaches the last element, since the last element doesn't have a next lement to compare it with
        {
            //comparing the current element vs the next element
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
            if (!swapped)   //if there were no swaps made (i.e if swapped is false, then break)
                break;
        }
    }

    for(const auto &a:array)
    {
        std::cout << a << " ";
    }
    return 0;
}
*/

