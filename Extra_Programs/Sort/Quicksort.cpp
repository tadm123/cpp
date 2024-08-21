/*
Quicksort

It's a recursive sorting method. Works by by selecting a random pivot in an array. Partitioning the smaller numbers to the left
of the pivot and the larger numbers to the right of the pivot. 
Do this recursively for sub-arrays.

Time complexity: Best: O(n log n), Worse: O(n^2)
Space comlexity: Best: O(log n)), Worst: O(n)

*/


#include <iostream>
#include <vector>
#include <utility> //for std::swap()
#include <cstdlib> //for random number generator rand()
#include <ctime>   //for time()

void quicksort(std::vector<int>& array, int length);
void quicksort_recursion(std::vector<int>& array, int low, int high);
int partition(std::vector<int>& array, int low, int high);


void quicksort_recursion(std::vector<int>& array, int low , int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);
        quicksort_recursion(array, low, pivot_index - 1);
        quicksort_recursion(array, pivot_index + 1, high);
    }
}

void quicksort(std::vector<int>& array, int length)
{
    srand(time(nullptr));     //sets seed base to current time
    quicksort_recursion(array, 0 , length - 1);
}


int partition(std::vector<int>& array, int low, int high)
{
    int pivot_index{ low + (rand() % (high - low + 1)) };

    if (pivot_index != high)
    {
        std::swap(array[pivot_index], array[high]);;
    }
    int pivot_value{ array[high] };
    int i{low};

    for(int j{low}; j < high; j++)
    {
        if (array[j] <= pivot_value)
        {
            std::swap(array[i], array[j]);
            i++;
        }
    }

    std::swap(array[i], array[high]);

    return i;
}

int main()
{
    std::vector <int> a{10,11,23,44,8,15,3,9,12,45,56,45,45};
    int length { static_cast<int>(a.size()) };

    // Apply the quicksort algorithm to sort the array
    quicksort(a, length);

    // For range loop to print the array elements
    for (const auto& elem: a)
    {
        std::cout << elem << " ";
    }

    return 0;
}
